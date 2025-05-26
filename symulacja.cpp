#include "symulacja.h"
#include "wartosczadana.h"
#include <iostream>
#include <iomanip>

Symulacja::Symulacja(QObject *parent)
    : QObject{parent}
    , m_pid(PID(0.0, 0.0, 0.0))
    , m_arx(ARX(-0.4, 0.0, 0.0, 0.6, 0.0, 0.0, 1))
    , m_wartosc_zadana(WartoscZadana(TypWartosciZadanej::SkokJednostkowy, 10.0, 4, 10.0))
    , m_zaklocenia(Zaklocenia(0.0, 0.1))
    , m_i(0)    /*, m_opoznienie(3)*/
    , m_poprz_y(0)
    , m_socket(this)
    , m_isConnectedToServer{false}
    , m_server(this)
    , m_isListening{false}
{
    m_klatki_symulacji = std::vector<KlatkaSymulacji>();
    // m_zaklocenia = Zaklocenia(0.0, 0.1);

    // connecty do klienta
    QAbstractSocket::connect(&m_socket, SIGNAL(connected()),
                             this, SLOT(s_connected()));
    QAbstractSocket::connect(&m_socket, SIGNAL(disconnected()),
                             this, SIGNAL(disconnected()));
    QAbstractSocket::connect(&m_socket, SIGNAL(readyRead()),
                             this, SLOT(s_receiveFromServer()));

    // connecty do serwera
    QAbstractSocket::connect(&m_server, SIGNAL(newConnection()),
                             this, SLOT(s_newClient()));
    QAbstractSocket::connect(this, SIGNAL(sent()),
                             parent, SLOT(s_drawSeriesOnServer()));
    QAbstractSocket::connect(this, SIGNAL(updateSettings(bool)),
                             parent, SLOT(zaktualizuj_wartosci(bool)));

}

/* Jedna z najważniejszych funkcji w tym programi.
 * Tutaj wyliczane są kolejne klatki symulacji.
 * Wszystko w takiej kolejności żeby to miało sens.
 */
void Symulacja::nastepna_klatka()
{
    // qDebug() << "next frame";
    // jeśli aplikacja jest offline lub jest połączona jako klient
    if (m_con_klient == nullptr) {

        m_nowe_w = m_wartosc_zadana.generuj(m_i);
        m_nowe_z = m_zaklocenia.generuj(m_i);
        // double m_nowe_e = m_nowe_w - m_arx.get_poprz_y();
        m_nowe_e = m_nowe_w - m_poprz_y;
        m_nowe_u = m_pid(m_nowe_e);

        if (isConnected()){
            if (!m_klatki_symulacji.empty())
                sendToServer(m_klatki_symulacji.back());
            else {
                KlatkaSymulacji nowa_klatka = KlatkaSymulacji(m_nowe_w,
                                                              m_nowe_e,
                                                              m_nowe_u,
                                                              0.0,
                                                              m_nowe_z,
                                                              m_pid.get_poprz_p(),
                                                              m_pid.get_poprz_i(),
                                                              m_pid.get_poprz_d());
                sendToServer(nowa_klatka);
            }

        }
        else {

            double nowe_y = m_arx(m_nowe_u, m_nowe_z);
            m_poprz_y = nowe_y;
            KlatkaSymulacji nowa_klatka = KlatkaSymulacji(m_nowe_w,
                                                          m_nowe_e,
                                                          m_nowe_u,
                                                          nowe_y,
                                                          m_nowe_z,
                                                          m_pid.get_poprz_p(),
                                                          m_pid.get_poprz_i(),
                                                          m_pid.get_poprz_d());
            m_klatki_symulacji.push_back(nowa_klatka);
            m_i++;
        }

    }
}

// klient
void Symulacja::sendToServer(const KlatkaSymulacji& data_to_send) {
    if (!isConnected())
        return;     // wyrzucić wyjątek ??

    QByteArray clientData;
    const short SIZE = sizeof(KlatkaSymulacji);  // nadmierne przesyłanie danych - nie trzeba ARX (7)
    clientData = QByteArray::fromRawData(reinterpret_cast<const char*>(&data_to_send), SIZE);

    m_socket.write(clientData);
}


// klient
void Symulacja::s_connected() {
    m_isConnectedToServer = true;
    emit connected(m_IP, m_port);
}

void Symulacja::s_receiveFromServer() {
    double new_y = m_socket.readAll().toDouble();
    // qDebug() << new_y;
    KlatkaSymulacji nowa_klatka = KlatkaSymulacji(m_nowe_w,
                                                  m_nowe_e,
                                                  m_nowe_u,
                                                  new_y + m_nowe_z,
                                                  m_nowe_z,
                                                  m_pid.get_poprz_p(),
                                                  m_pid.get_poprz_i(),
                                                  m_pid.get_poprz_d());
    m_poprz_y = new_y;
    m_i++;
    m_klatki_symulacji.push_back(nowa_klatka);

}

// serwer
void Symulacja::s_newClient() {
    QTcpSocket *klient = m_server.nextPendingConnection();
    m_con_klient = klient;

    QString adr = klient->peerAddress().toString();
    QAbstractSocket::connect(m_con_klient, SIGNAL(disconnected()),
                             this, SLOT(s_clientDisc()));
    QAbstractSocket::connect(m_con_klient, SIGNAL(readyRead()),
                             this, SLOT(s_receiveFromClient()));

    emit clientConnected(adr);
}

void Symulacja::s_clientDisc() {
    delete m_con_klient;
    m_con_klient = nullptr;
    emit clientDisconnected();
}

void Symulacja::s_receiveFromClient() {

    if (m_con_klient == nullptr)
        return;     // wyrzucić wyjątek ??

    QByteArray received_data = m_con_klient->readAll();
    KlatkaSymulacji deserialized_data;
    std::memcpy(&deserialized_data, received_data, sizeof(KlatkaSymulacji));

    emit updateSettings(true);
    // qDebug() << deserialized_data.get_z();
    double new_y = m_arx(deserialized_data.get_u(), deserialized_data.get_z());
    emit sent();

    KlatkaSymulacji nowa_klatka = KlatkaSymulacji(deserialized_data.get_w(),
                                                  deserialized_data.get_e(),
                                                  deserialized_data.get_u(),
                                                  new_y + deserialized_data.get_z(),
                                                  deserialized_data.get_z(),
                                                  deserialized_data.get_p(),
                                                  deserialized_data.get_i(),
                                                  deserialized_data.get_d()
                                                  );

    m_klatki_symulacji.push_back(nowa_klatka);

    QByteArray new_data_serialized;
    new_data_serialized = QByteArray::number(new_y);

    m_con_klient->write(new_data_serialized);
}



/* Settery i gettery.
 */
std::vector<KlatkaSymulacji> *Symulacja::get_klatki_symulacji()
{
    return &m_klatki_symulacji;
}
void Symulacja::set_klatki_symulacji(std::vector<KlatkaSymulacji> wartosc)
{
    m_klatki_symulacji = wartosc;
}
PID *Symulacja::get_pid()
{
    return &m_pid;
}
ARX *Symulacja::get_arx()
{
    return &m_arx;
}
WartoscZadana *Symulacja::get_wartosc_zadana()
{
    return &m_wartosc_zadana;
}
// Zaklocenia* Symulacja::get_zaklocenia() { return &m_zaklocenia; }
void Symulacja::set_i(int wartosc)
{
    m_i = wartosc;
}
void Symulacja::set_opoznienie(int wartosc)
{
    m_arx.set_opoznienie(wartosc);
}
void Symulacja::set_zaklocenia(double srednia, double odchylenie)
{
    m_zaklocenia.set_srednia(srednia);
    m_zaklocenia.set_odchylenie(odchylenie);
}


// klient
void Symulacja::connect(QString ip_addr, int port) {
    m_socket.connectToHost(ip_addr, port);
    m_IP = ip_addr;
    m_port = port;
}

void Symulacja::disconnect() {
    m_socket.close();
    m_isConnectedToServer = false;
    // qDebug() << "client disconnect";
}

bool Symulacja::isConnected() {
    return m_isConnectedToServer;
}


// serwer
void Symulacja::startListening(int port) {
    m_port = port;
    m_isListening = m_server.listen(QHostAddress::AnyIPv4, port);
}

void Symulacja::stopListening() {
    m_server.close();
    m_isListening = false;
}

bool Symulacja::isListening() {
    return m_isListening;
}

