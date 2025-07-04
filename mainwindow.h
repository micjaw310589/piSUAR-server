#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QImage>
#include <QMainWindow>
#include <QTimer>
#include <QtCharts>
#include "symulacja.h"
#include "dialogarx.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // void start_simulation();
    // void stop_simulation();

public slots:
    void accepted_dialog_arx();

private slots:
    void timer_timeout_slot();

    void zaktualizuj_wartosci(bool aktualizuj_arx = true);

    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_resetButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();
    void on_updateButton_clicked();
    void on_zeruj_czesc_calkujaca_clicked();
    void on_zmien_ustawienia_arx_clicked();
    void on_btnPolacz_clicked();
    void on_btnRozlacz_clicked();
    void on_ckbServer_checkStateChanged(const Qt::CheckState &arg1);

    // klient
    void s_connected(QString, int);
    void s_disconnected();

    // serwer
    void s_clientConnected(QString);
    void s_clientDisconnected();
    void s_drawSeriesOnServer(int nr_kroku);

    void s_error_handling(const QAbstractSocket::SocketError &err);

private:
    Ui::MainWindow *ui;
    int ODSWIEZANIE = 150;   // Co tyle milisekund będą się wywoływać następne klatki animacji
    const int ZAKRES_WYKRESU = 40; // Im mniej, tym sprawniej działa, bo pętla ma mniej do zrobienia
    unsigned long long m_last_klatki_symulacji_size;
    QTimer *timer = nullptr;
    QLineSeries *wykres_wartosci_zadanej;
    // QLineSeries *wykres_zakolcen;
    QLineSeries *wykres_uchybu;
    QLineSeries *wykres_pid;
    QLineSeries *wykres_p;
    QLineSeries *wykres_i;
    QLineSeries *wykres_d;
    QLineSeries *wykres_arx;
    QChart *chart = nullptr;
    QChart *chart_pid = nullptr;
    QChart *chart_arx = nullptr;
    QChartView *chart_view = nullptr;
    QChartView *chart_pid_view = nullptr;
    QChartView *chart_arx_view = nullptr;
    Symulacja *symulacja = nullptr;
    DialogARX *dialog_arx = nullptr;


    QString sklejAdresIP();
    bool sprawdzPoprawnosc(QString IP, int port);
    bool sprawdzPoprawnosc(int port);
    void resetujKlienta();
    void resetujSerwer();
    bool clientConnected;
    bool isConnected();
};
#endif // MAINWINDOW_H
