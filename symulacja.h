#ifndef SYMULACJA_H
#define SYMULACJA_H

#include <QTimer>
#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include "arx.h"
#include "klatkasymulacji.h"
#include "pid.h"
#include "wartosczadana.h"
#include "zaklocenia.h"
#include "frametoserver.h"
#include "frametoclient.h"
#include <vector>

class Symulacja : public QObject
{
    Q_OBJECT

private:
    std::vector<KlatkaSymulacji> m_klatki_symulacji;
    PID m_pid;
    ARX m_arx;
    WartoscZadana m_wartosc_zadana;
    Zaklocenia m_zaklocenia;
    int m_aktualny_krok;
    int m_ostatni_krok;
    bool shouldServerBeRunning;
    bool resetOrderFromClient;
    double m_poprz_y;

    double m_nowe_w;
    double m_nowe_z;
    double m_nowe_e;
    double m_nowe_u;

    // do trybu sieciowego
    int m_port;

    // klient
    QTcpSocket m_socket;
    QString m_IP;
    bool m_isConnectedToServer;
    // klient
    // void sendToServer(const KlatkaSymulacji& data_to_send);
    void sendToServer(const FrameToServer& data_to_send);

    // serwer
    QTcpServer m_server;
    QTcpSocket* m_con_klient = nullptr;
    bool m_isListening;

signals:
    // klient
    void connected(QString adr, int port);
    void disconnected();

    // serwer
    void clientConnected(QString adr);
    void clientDisconnected();
    void sent(int nr_kroku);
    void updateSettings(bool aktualizuj_arx);
    void signalReset();
    void signalStart();
    void signalStop();

private slots:
    // klient
    void s_connected();
    void s_receiveFromServer();

    // serwer
    void s_newClient();
    void s_clientDisc();
    void s_receiveFromClient();

public:
    Symulacja(QObject *parent = nullptr);
    void nastepna_klatka();

    std::vector<KlatkaSymulacji> *get_klatki_symulacji();
    void set_klatki_symulacji(std::vector<KlatkaSymulacji>);
    PID *get_pid();
    ARX *get_arx();
    WartoscZadana *get_wartosc_zadana();
    int get_ostatni_krok() { return m_ostatni_krok; }
    // Zaklocenia* get_zaklocenia();
    void set_aktualny_krok(int);
    void set_ostatni_krok(int);
    void set_shouldServerBeRunning(bool);
    void set_resetOrderFromClient(bool);
    void set_opoznienie(int);
    void set_zaklocenia(double srednia, double odchylenie);

    // klient
    // const QTcpSocket* getKlient() { return &m_socket; }
    void connect(QString, int);
    void disconnect();
    bool isConnected();

    // serwer
    const QTcpSocket* getConKlient() { return m_con_klient; }
    void startListening(int port);
    void stopListening();
    bool isListening();
};

#endif // SYMULACJA_H
