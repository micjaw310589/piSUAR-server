#include "symulacja.h"
#include "wartosczadana.h"

Symulacja::Symulacja()
    : m_pid(PID(0.0, 0.0, 0.0))
    , m_arx(ARX(-0.4, 0.0, 0.0, 0.6, 0.0, 0.0, 1))
    , m_wartosc_zadana(WartoscZadana(TypWartosciZadanej::SkokJednostkowy, 10.0, 4, 10.0))
    , m_zaklocenia(Zaklocenia(0.0, 0.1))
    , m_i(0) /*, m_opoznienie(3)*/
{
    m_klatki_symulacji = std::list<KlatkaSymulacji>();
    // m_zaklocenia = Zaklocenia(0.0, 0.1);
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
