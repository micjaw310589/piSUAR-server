#ifndef SYMULACJA_H
#define SYMULACJA_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include "arx.h"
#include "klatkasymulacji.h"
#include "pid.h"
#include "wartosczadana.h"
#include "zaklocenia.h"
#include <list>

class Symulacja : public QObject
{
    Q_OBJECT

private:
    std::list<KlatkaSymulacji> m_klatki_symulacji;
    PID m_pid;
    ARX m_arx;
    WartoscZadana m_wartosc_zadana;
    Zaklocenia m_zaklocenia;
    int m_i;
    // int m_opoznienie;

    QTcpServer m_server;
    QVector<QTcpSocket*> m_klienci;
    QTcpSocket m_socket;
    QString m_IP;
    int m_port;
    bool m_isListening;

    bool getIDKlienta();

signals:
    // klient
    void connected(QString adr, int port);
    void disconnected();

    // serwer
    void clientConnected(QString adr);
    void clientDisconnected();

private slots:
    // klient
    void s_connected();

    // serwer
    void s_newClient();
    void s_clientDisc();

public:
    Symulacja(QObject *parent = nullptr);
    void nastepna_klatka();

    std::list<KlatkaSymulacji> *get_klatki_symulacji();
    void set_klatki_symulacji(std::list<KlatkaSymulacji>);
    PID *get_pid();
    ARX *get_arx();
    WartoscZadana *get_wartosc_zadana();
    // Zaklocenia* get_zaklocenia();
    void set_i(int);
    void set_opoznienie(int);
    void set_zaklocenia(double srednia, double odchylenie);

    // klient
    void connect(QString, int);
    void disconnect();
    // bool isConnected();

    // serwer
    void startListening(int port);
    void stopListening();
    bool isListening();
    int getNumOfClients();
};

#endif // SYMULACJA_H
