#include "pid.h"

PID::PID(double nowe_k, double nowe_ti, double nowe_td)
    : m_k(nowe_k)
    , m_ti(nowe_ti)
    , m_td(nowe_td)
    , m_historia_uchybow(std::vector<double>())
    , m_poprz_p(1.0)
    , m_poprz_i(0.0)
    , m_poprz_d(0.0)
    , m_sposob_wyliczania_calki(false)
{}

/* Do zerowaina całki.
 */
void PID::zeruj_calke()
{
    m_historia_uchybow.clear();
}

/* Liczy część proporcjonalną.
 */
double PID::P()
{
    if (m_historia_uchybow.size() < 1)
        return 0.0;
    return m_k * m_historia_uchybow.at(m_historia_uchybow.size() - 1);
}

/* Liczy część całkującą.
 */
double PID::I()
{
    // Nie dzielimy przez zero
    if (m_ti == 0.0)
        return 0.0;
    double wynik = 0.0;
    // Dla wektora 0 długości nie powinno się uruchomić,
    // więc nie trzeba się przed tym tutaj zabezpieczać w pętli
    if (m_sposob_wyliczania_calki)
    {
        for (auto e: m_historia_uchybow)
        {
            wynik += e/m_ti;
        }
        return wynik;
    }
    else
    {
        for (auto e : m_historia_uchybow)
        {
            wynik += e;
        }
        return wynik / m_ti;
    }
}

/* Liczy część różniczkującą.
 */
double PID::D()
{
    if (m_historia_uchybow.size() == 0)
        return 0.0;
    else if (m_historia_uchybow.size() == 1)
        return m_td * m_historia_uchybow.at(0);
    else {
        return m_td
               * (m_historia_uchybow.at(m_historia_uchybow.size() - 1)
                  - m_historia_uchybow.at(m_historia_uchybow.size() - 2));
    }
}

/* Podobnie jak w ARK, jest tutaj deklaracja funktora.
 * Skleja poszczególne etapy wyliczania PID i to zwraca.
 */
double PID::operator()(double uchyb)
{
    // Zapisz nowy uchyb
    m_historia_uchybow.push_back(uchyb);
    // Wylicz następny wynik PID
    double wynik = 0.0;
    m_poprz_p = P();
    wynik += m_poprz_p;
    m_poprz_i = I();
    wynik += m_poprz_i;
    m_poprz_d = D();
    wynik += m_poprz_d;
    // qInfo() << m_poprz_p;
    return wynik;
}

/* Setter współczynników PID.
 */
void PID::zmien_wspolczynniki(double nowe_k, double nowe_ti, double nowe_td)
{
    m_k = nowe_k;
    m_ti = nowe_ti;
    m_td = nowe_td;
}

/* Gettery
 */
double PID::get_poprz_p()
{
    return m_poprz_p;
}
double PID::get_poprz_i()
{
    return m_poprz_i;
}
double PID::get_poprz_d()
{
    return m_poprz_d;
}

/* Setter dla sposobu wyliczania całki.
 */
void PID::set_sposob_wyliczania_calki(bool wartosc)
{
    m_sposob_wyliczania_calki = wartosc;
}
