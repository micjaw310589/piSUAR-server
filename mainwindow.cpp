#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <algorithm>
#include "dialogarx.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Inicjalizacja i podpięcie timera
     */
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_timeout_slot()));
    /* Inicjalizacja backendu w postaci klasy symulacji
     */
    symulacja = new Symulacja();
    /* Definicje poszczególnych linii wykresów
     */
    wykres_wartosci_zadanej = new QLineSeries;
    wykres_wartosci_zadanej->setName("wartość zadana");
    wykres_uchybu = new QLineSeries;
    wykres_uchybu->setName("Uchyb");
    wykres_pid = new QLineSeries;
    wykres_pid->setName("PID");
    wykres_p = new QLineSeries;
    wykres_p->setName("P");
    wykres_i = new QLineSeries;
    wykres_i->setName("I");
    wykres_d = new QLineSeries;
    wykres_d->setName("D");
    wykres_arx = new QLineSeries;
    wykres_arx->clear();
    wykres_arx->setName("ARX");
    /* Wykres Uchybu.
     * Wyświetla się na samym spodzie, jeśli dobrze pamiętam.
     */
    chart = new QChart();
    chart->addSeries(wykres_uchybu);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 5);
    chart->axes(Qt::Horizontal).first()->setRange(0, 5);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setVisible(true);
    chart_view = new QChartView(chart);
    chart_view->setVisible(true);
    /* Wykres PID
     */
    chart_pid = new QChart();
    chart_pid->addSeries(wykres_pid);
    chart_pid->addSeries(wykres_p);
    chart_pid->addSeries(wykres_i);
    chart_pid->addSeries(wykres_d);
    chart_pid->createDefaultAxes();
    chart_pid->axes(Qt::Vertical).first()->setRange(0, 5);
    chart_pid->axes(Qt::Horizontal).first()->setRange(0, 5);
    chart_pid->setTheme(QChart::ChartThemeDark);
    chart_pid->setVisible(true);
    chart_pid_view = new QChartView(chart_pid);
    chart_pid_view->setVisible(true);
    /* Wykres ARX
     */
    chart_arx = new QChart();
    chart_arx->addSeries(wykres_wartosci_zadanej);
    chart_arx->addSeries(wykres_arx);
    chart_arx->createDefaultAxes();
    chart_arx->axes(Qt::Vertical).first()->setRange(0, 5);
    chart_arx->axes(Qt::Horizontal).first()->setRange(0, 5);
    chart_arx->setTheme(QChart::ChartThemeDark);
    chart_arx->setVisible(true);
    chart_arx_view = new QChartView(chart_arx);
    chart_arx_view->setVisible(true);
    /* Podpięcie wykresów do GUI
     */
    ui->wykres->hide();
    ui->verticalLayout_3->addWidget(chart_pid_view);
    ui->verticalLayout_3->addWidget(chart_arx_view);
    ui->verticalLayout_3->addWidget(chart_view);
    /* Podpięcie oknra aktualizacji wartośći ARX
     */
    dialog_arx = new DialogARX();
    connect(dialog_arx, SIGNAL(accepted()),
            this, SLOT(accepted_dialog_arx()));
}

// Tutaj przetwarzana jest każda nowa klatka symulacji
void MainWindow::timer_timeout_slot()
{
    zaktualizuj_wartosci(false);  // Tutaj ustawiam aktualizowanie się wartości z lewego panelu, z wyłączeniem ARX
    ODSWIEZANIE = ui->interwal->value();  // Zczytuję z dolnego panelu jak często ma się symulacja wywoływać
    timer->start(ODSWIEZANIE);  // Ustawiamy jak często mają się klatki odświeżać
    symulacja->nastepna_klatka();  // Wywołanie następnej klatki symulacji
    /* Czyszczenie wykresów
     */
    wykres_wartosci_zadanej->clear();
    wykres_uchybu->clear();
    wykres_pid->clear();
    wykres_p->clear();
    wykres_i->clear();
    wykres_d->clear();
    wykres_arx->clear();
    /* Reset/inicjacja zakresów używanych przy zapełnianiu wykresów
     */
    int offset = 0;
    double wartosc_max = 0.0;
    double wartosc_min = 0.0;
    double wartosc_max_pid = 0.0;
    double wartosc_min_pid = 0.0;
    double wartosc_max_arx = 0.0;
    double wartosc_min_arx = 0.0;
    /* Offset będzie użyty tylko, jeśli miałby się niezmieścić na wykresie (wszerz).
     * Domyślnie pozostanie 0 i program postara się wyświetlić wszystko.
     */
    if (symulacja->get_klatki_symulacji()->size() > ZAKRES_WYKRESU) {
        offset = (int) symulacja->get_klatki_symulacji()->size() - ZAKRES_WYKRESU;
    }
    /* Ustawianie horyzontalnych osi dla wszystkich 3 wykresów
     */
    chart->axes(Qt::Horizontal).first()->setRange(offset, symulacja->get_klatki_symulacji()->size());
    chart_pid->axes(Qt::Horizontal).first()->setRange(offset, symulacja->get_klatki_symulacji()->size());
    chart_arx->axes(Qt::Horizontal).first()->setRange(offset, symulacja->get_klatki_symulacji()->size());
    /* Tutaj ustawiamy iterator na początek listy, a następnie przesuwamy go o offset.
     */
    auto iterator_klatka_symulacji = symulacja->get_klatki_symulacji()->begin();
    std::advance(iterator_klatka_symulacji, offset);
    /* Teraz używamy iteratora do przeiterowania się po nim aż do jego końca.
     * Dzięki temu nie wyświetlamy najstarszych wartości. Tylko te które powinny się zmieścić na wykresie.
     * To zakłada że offset jest już poprawnie ustawiony.
     * Poza tym, tutaj jest wyliczane, na ile ustawić pionowe osie.
     */
    for (size_t i = offset; i < symulacja->get_klatki_symulacji()->size(); i++) {
        /* Wykres uchybu
         */
        wykres_uchybu->append(i, iterator_klatka_symulacji->get_e());
        wartosc_min = std::min(wartosc_min, iterator_klatka_symulacji->get_e());
        wartosc_max = std::max(wartosc_max, iterator_klatka_symulacji->get_e());
        /* Wykres PID
         */
        wykres_pid->append(i, iterator_klatka_symulacji->get_u());
        wartosc_min_pid = std::min(wartosc_min_pid, iterator_klatka_symulacji->get_u());
        wartosc_max_pid = std::max(wartosc_max_pid, iterator_klatka_symulacji->get_u());
        wykres_p->append(i, iterator_klatka_symulacji->get_p());
        wartosc_min_pid = std::min(wartosc_min_pid, iterator_klatka_symulacji->get_p());
        wartosc_max_pid = std::max(wartosc_max_pid, iterator_klatka_symulacji->get_p());
        wykres_i->append(i, iterator_klatka_symulacji->get_i());
        wartosc_min_pid = std::min(wartosc_min_pid, iterator_klatka_symulacji->get_i());
        wartosc_max_pid = std::max(wartosc_max_pid, iterator_klatka_symulacji->get_i());
        wykres_d->append(i, iterator_klatka_symulacji->get_d());
        wartosc_min_pid = std::min(wartosc_min_pid, iterator_klatka_symulacji->get_d());
        wartosc_max_pid = std::max(wartosc_max_pid, iterator_klatka_symulacji->get_d());
        /* Wykres ARX
         */
        wykres_wartosci_zadanej->append(i, iterator_klatka_symulacji->get_w());
        wartosc_min_arx = std::min(wartosc_min_arx, iterator_klatka_symulacji->get_w());
        wartosc_max_arx = std::max(wartosc_max_arx, iterator_klatka_symulacji->get_w());
        wykres_arx->append(i, iterator_klatka_symulacji->get_y());
        wartosc_min_arx = std::min(wartosc_min_arx, iterator_klatka_symulacji->get_y());
        wartosc_max_arx = std::max(wartosc_max_arx, iterator_klatka_symulacji->get_y());
        std::advance(iterator_klatka_symulacji, 1);
    }
    /* Aktualizacja pionowych osi na wykresach.
     */
    chart->axes(Qt::Vertical).first()->setRange(wartosc_min, wartosc_max);
    chart_pid->axes(Qt::Vertical).first()->setRange(wartosc_min_pid, wartosc_max_pid);
    chart_arx->axes(Qt::Vertical).first()->setRange(wartosc_min_arx, wartosc_max_arx);
}

void MainWindow::zaktualizuj_wartosci(bool aktualizuj_arx = true)
{
    // Update opóźnienia
    symulacja->set_opoznienie(ui->opoznienie->value());
    // Update wartości zadanej
    TypWartosciZadanej typ;
    if (ui->sygnalSkokowy->isChecked())
        typ = TypWartosciZadanej::SkokJednostkowy;
    else if (ui->sygnalSinusoida->isChecked())
        typ = TypWartosciZadanej::Sinusoida;
    else
        typ = TypWartosciZadanej::SygnalProstokatny;
    symulacja->get_wartosc_zadana()->zmien_sygnal(typ,
                                                  ui->wartoscZadanaA->value(),
                                                  ui->wartoscZadanaT->value(),
                                                  ui->wartoscZadanaP->value());
    // Update PID
    symulacja->get_pid()->zmien_wspolczynniki(ui->pidK->value(),
                                              ui->pidTi->value(),
                                              ui->pidTd->value());
    symulacja->get_pid()->set_sposob_wyliczania_calki(ui->sposob_wyliczania_calki->isChecked());
    if (!ui->sposob_wyliczania_calki->isChecked())
    {
        ui->sposob_wyliczania_calki->setText("Sumowanie przed całką");
    }
    else
    {
        ui->sposob_wyliczania_calki->setText("Sumowanie w całce");
    }
    // Update ARX
    if (aktualizuj_arx)
    {
        symulacja->get_arx()->set_a(ui->arx_a->value(), ui->arx_a_2->value(), ui->arx_a_3->value());
        symulacja->get_arx()->set_b(ui->arx_b->value(), ui->arx_b_2->value(), ui->arx_b_3->value());
    }
    // Update Zaklocen
    symulacja->set_zaklocenia(ui->zaklocenie_sred->value(), ui->zaklocenie_odchylenie->value());
}

MainWindow::~MainWindow()
{
    // if (wykres_obraz != nullptr) delete wykres_obraz;
    delete chart;
    delete chart_pid;
    delete chart_arx;
    delete chart_view;
    delete chart_pid_view;
    delete chart_arx_view;
    delete symulacja;
    delete timer;
    delete dialog_arx;
    delete ui;
}

/* Rozpoczyna symulację.
 */
void MainWindow::on_startButton_clicked()
{
    zaktualizuj_wartosci();
    symulacja->set_opoznienie(ui->opoznienie->value()); // Nadpisanie opóźnienia dla nowej symulacji
    timer->start(ODSWIEZANIE);
}

/* Zatrzymuje symulację.
 */
void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}

/* Resetuje wartości symulacji.
 * Zauważcie że nie uruchamia jej automatycznie.
 * Wymagana jest osobna akcja.
 */
void MainWindow::on_resetButton_clicked()
{
    timer->stop();
    symulacja->set_i(0);                                // Reset i klatki symulacji
    symulacja->set_klatki_symulacji(std::list<KlatkaSymulacji>()); // Nadpisanie listy
    wykres_wartosci_zadanej->clear();
    wykres_uchybu->clear();
    wykres_pid->clear();
    wykres_p->clear();
    wykres_i->clear();
    wykres_d->clear();
    wykres_arx->clear();
    delete symulacja;
    symulacja = new Symulacja();
    zaktualizuj_wartosci();
}

/* Zapisuje ustawienia paneli sterowania.
 * Prawdopodobnie nie będzie was to interesowało, ale lepiej zostawić, żeby przypadkiem nie popsuć.
 */
void MainWindow::on_saveButton_clicked()
{
    QFile plik("Plik.dane");
    if(!plik.open(QIODevice::WriteOnly))
    {
        qCritical() << "Nie udało się otworzyć pliku:" << plik.errorString();
        return;
    }
    QDataStream strumien(&plik);
    // Tutaj możemy zapisać już po kolei wszystkie dane
    // Ważne żeby przy odczycie odczytać je w tej samej kolejności co zostały zapisane
    strumien << ui->wartoscZadanaA->value();
    strumien << ui->wartoscZadanaT->value();
    strumien << ui->wartoscZadanaP->value();
    strumien << ui->sygnalSkokowy->isChecked();
    strumien << ui->sygnalSinusoida->isChecked();
    strumien << ui->sygnalProstakat->isChecked();
    strumien << ui->zaklocenie_sred->value();
    strumien << ui->zaklocenie_odchylenie->value();
    strumien << ui->pidK->value();
    strumien << ui->pidTd->value();
    strumien << ui->pidTi->value();
    strumien << ui->opoznienie->value();
    strumien << ui->arx_a->value();
    strumien << ui->arx_a_2->value();
    strumien << ui->arx_a_3->value();
    strumien << ui->arx_b->value();
    strumien << ui->arx_b_2->value();
    strumien << ui->arx_b_3->value();
    plik.close();
}

/* Wczytuje ustawienia o ile były one zapisane w funkcji powyżej.
 */
void MainWindow::on_loadButton_clicked()
{
    QFile plik("Plik.dane");
    if(!plik.exists())
    {
        qWarning() << "Nie znaleziono pliku do odczytu." << plik.errorString();
        return;
    }
    if(!plik.open(QIODevice::ReadOnly))
    {
        qCritical() << "Nie udało się otworzyć pliku:" << plik.errorString();
        return;
    }
    QDataStream strumien(&plik);
    double wartoscZadanaA;
    strumien >> wartoscZadanaA;
    ui->wartoscZadanaA->setValue(wartoscZadanaA);
    int wartoscZadanaT;
    strumien >> wartoscZadanaT;
    ui->wartoscZadanaT->setValue(wartoscZadanaT);
    double wartoscZadanaP;
    strumien >> wartoscZadanaP;
    ui->wartoscZadanaP->setValue(wartoscZadanaP);
    bool sygnalSkok;
    strumien >> sygnalSkok;
    ui->sygnalSkokowy->setChecked(sygnalSkok);
    bool sygnalSinus;
    strumien >> sygnalSinus;
    ui->sygnalSinusoida->setChecked(sygnalSinus);
    bool sygnalProstakat;
    strumien >> sygnalProstakat;
    ui->sygnalProstakat->setChecked(sygnalProstakat);
    double zakloceniaSrednia;
    strumien >> zakloceniaSrednia;
    ui->zaklocenie_sred->setValue(zakloceniaSrednia);
    double zakloceniaOdchyl;
    strumien >> zakloceniaOdchyl;
    ui->zaklocenie_odchylenie->setValue(zakloceniaOdchyl);
    double pidK;
    strumien >> pidK;
    ui->pidK->setValue(pidK);
    double pidTd;
    strumien >> pidTd;
    ui->pidTd->setValue(pidTd);
    double pidTi;
    strumien >> pidTi;
    ui->pidTi->setValue(pidTi);
    int opoznienie;
    strumien >> opoznienie;
    ui->opoznienie->setValue(opoznienie);
    double arxA;
    strumien >> arxA;
    ui->arx_a->setValue(arxA);
    double arxAA;
    strumien >> arxAA;
    ui->arx_a_2->setValue(arxAA);
    double arxAAA;
    strumien >> arxAAA;
    ui->arx_a_3->setValue(arxAAA);
    double arxB;
    strumien >> arxB;
    ui->arx_b->setValue(arxB);
    double arxBB;
    strumien >> arxBB;
    ui->arx_b_2->setValue(arxBB);
    double arxBBB;
    strumien >> arxBBB;
    ui->arx_b_3->setValue(arxBBB);
    plik.close();
}

/* Dostaliśmy wymóg, że wrtości miały się aktualizować dopiero po przyciśnięciu tego przycisku.
 * W tym semestrze okazuje się być znowu na opak, ale już zostawiam ten przycisk.
 * Można tą funkcjonalność uznać za legacy kod.
 */
void MainWindow::on_updateButton_clicked()
{
    zaktualizuj_wartosci();
}

/* Nowy wymóg.
 * Kasuje pamięć części całkującej w PID.
 */
void MainWindow::on_zeruj_czesc_calkujaca_clicked()
{
    symulacja->get_pid()->zeruj_calke();
}

/* Wczytuje do dialogu ARX, a następnie go wyświetla.
 * Ten dialog nie blokuje okna głównego.
 */
void MainWindow::on_zmien_ustawienia_arx_clicked()
{
    dialog_arx->set_wartosci(
        ui->arx_a->value(),
        ui->arx_a_2->value(),
        ui->arx_a_3->value(),
        ui->arx_b->value(),
        ui->arx_b_2->value(),
        ui->arx_b_3->value(),
        ui->opoznienie->value()
    );
    dialog_arx->exec();
}

/* Tutaj obsługiwany jest sygnał z dialogu ARX.
 */
void MainWindow::accepted_dialog_arx()
{
    double a1, a2, a3, b1, b2, b3;
    int opoznienie;
    dialog_arx->get_wartosci(a1, a2, a3, b1, b2, b3, opoznienie);
    ui->arx_a->setValue(a1);
    ui->arx_a_2->setValue(a2);
    ui->arx_a_3->setValue(a3);
    ui->arx_b->setValue(b1);
    ui->arx_b_2->setValue(b2);
    ui->arx_b_3->setValue(b3);
    ui->opoznienie->setValue(opoznienie);
}
