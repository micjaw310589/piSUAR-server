#include "symulacja.h"
#include "wartosczadana.h"

Symulacja::Symulacja(QObject *parent)
    : QObject{parent}
    , m_pid(PID(0.0, 0.0, 0.0))
    , m_arx(ARX(-0.4, 0.0, 0.0, 0.6, 0.0, 0.0, 1))
    , m_wartosc_zadana(WartoscZadana(TypWartosciZadanej::SkokJednostkowy, 10.0, 4, 10.0))
    , m_zaklocenia(Zaklocenia(0.0, 0.1))
    , m_i(0)    /*, m_opoznienie(3)*/
    , m_server(this)
    , m_socket(this)
    , m_isListening{false}
{
    m_klatki_symulacji = std::list<KlatkaSymulacji>();
    // m_zaklocenia = Zaklocenia(0.0, 0.1);

    // connecty do klienta
    QAbstractSocket::connect(&m_socket, SIGNAL(connected()),
                             this, SLOT(s_connected()));
    QAbstractSocket::connect(&m_socket, SIGNAL(disconnected()),
                             this, SIGNAL(disconnected()));

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
    double nowe_w = m_wartosc_zadana.generuj(m_i);
    double nowe_z = m_zaklocenia.generuj(m_i);
    double nowe_e = nowe_w - m_arx.get_poprz_y();
    double nowe_u = m_pid(nowe_e);
    double nowe_y = m_arx(nowe_u, nowe_z);
    KlatkaSymulacji nowa_klatka = KlatkaSymulacji(nowe_w,
                                                  nowe_e,
                                                  nowe_u,
                                                  nowe_y,
                                                  nowe_z,
                                                  m_pid.get_poprz_p(),
                                                  m_pid.get_poprz_i(),
                                                  m_pid.get_poprz_d());
    m_klatki_symulacji.push_back(nowa_klatka);
    m_i++;
}

// klient
void Symulacja::s_connected() {
    emit connected(m_IP, m_port);
}

// serwer
void Symulacja::s_newClient() {
    QTcpSocket *klient = m_server.nextPendingConnection();
    m_con_klient = klient;

    QString adr = klient->peerAddress().toString();
    QAbstractSocket::connect(klient, SIGNAL(disconnected()),
                             this, SLOT(s_clientDisc()));

    emit clientConnected(adr);
}

void Symulacja::s_clientDisc() {
    delete m_con_klient;
    m_con_klient = nullptr;
    emit clientDisconnected();
}


/* Settery i gettery.
 */
std::list<KlatkaSymulacji> *Symulacja::get_klatki_symulacji()
{
    return &m_klatki_symulacji;
}
void Symulacja::set_klatki_symulacji(std::list<KlatkaSymulacji> wartosc)
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

