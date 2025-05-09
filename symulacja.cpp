#include "symulacja.h"
#include "wartosczadana.h"

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
}

/* Jedna z najważniejszych funkcji w tym programi.
 * Tutaj wyliczane są kolejne klatki symulacji.
 * Wszystko w takiej kolejności żeby to miało sens.
 */
void Symulacja::nastepna_klatka()
{
    // jeśli aplikacja jest offline lub jest połączona jako klient
    if (m_con_klient == nullptr) {

        m_nowe_w = m_wartosc_zadana.generuj(m_i);
        m_nowe_z = m_zaklocenia.generuj(m_i);
        // double m_nowe_e = m_nowe_w - m_arx.get_poprz_y();
        m_nowe_e = m_nowe_w - m_poprz_y;
        m_nowe_u = m_pid(m_nowe_e);

        if (isConnected()){
            sendToServer(m_nowe_u);
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
void Symulacja::sendToServer(double u_to_send) {
    QByteArray u_serial = QByteArray::number(u_to_send);
    if (isConnected())
        m_socket.write(u_serial);
}


// klient
void Symulacja::s_connected() {
    qDebug() << "client connected";
    m_isConnectedToServer = true;
    emit connected(m_IP, m_port);
}

void Symulacja::s_receiveFromServer() {
    double nowe_y = m_socket.readAll().toDouble();
    KlatkaSymulacji nowa_klatka = KlatkaSymulacji(m_nowe_w,
                                                  m_nowe_e,
                                                  m_nowe_u,
                                                  nowe_y + m_nowe_z,
                                                  m_nowe_z,
                                                  m_pid.get_poprz_p(),
                                                  m_pid.get_poprz_i(),
                                                  m_pid.get_poprz_d());
    m_klatki_symulacji.push_back(nowa_klatka);
    m_poprz_y = nowe_y;
    m_i++;

    qDebug() << nowe_y;
}

// serwer
void Symulacja::s_newClient() {
    QTcpSocket *klient = m_server.nextPendingConnection();
    m_con_klient = klient;

    QString adr = klient->peerAddress().toString();
    QAbstractSocket::connect(klient, SIGNAL(disconnected()),
                             this, SLOT(s_clientDisc()));
    QAbstractSocket::connect(klient, SIGNAL(readyRead()),
                             this, SLOT(s_receiveFromClient()));

    emit clientConnected(adr);
}

void Symulacja::s_clientDisc() {
    delete m_con_klient;
    m_con_klient = nullptr;
    emit clientDisconnected();
}

void Symulacja::s_receiveFromClient() {
    double u = m_con_klient->readAll().toDouble();
    double nowe_y = m_arx(u, 0.0);
    QByteArray nowe_y_serial = QByteArray::number(nowe_y);
    if (m_con_klient != nullptr)
        m_con_klient->write(nowe_y_serial);
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
    qDebug() << "client disconnect";
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

