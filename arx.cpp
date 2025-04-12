#include "arx.h"

ARX::ARX(double a, double a2, double a3, double b, double b2, double b3,  int opoznienie)
    : m_a(a)
    , m_a_2(a2)
    , m_a_3(a3)
    , m_b(b)
    , m_b_2(b2)
    , m_b_3(b3)
    , m_opoznienie(opoznienie)
    , m_historia_y(std::vector<double>())
    , m_historia_u(std::vector<double>())
{}

/* Ten operator wykożystywany jest w każdej klatce symulacji do wyliczania ARX.
 * Tutaj posklejane są poszczególne etapy wyliczania ARX.
 */
double ARX::operator()(double nowe_u, double z)
{
    double wynik;
    if (m_historia_u.size() >= 1 + m_opoznienie && m_historia_y.size() >= 1)
    {
        wynik = m_b * m_historia_u.at(m_historia_u.size() - 1 - m_opoznienie) - m_a * m_historia_y.at(m_historia_y.size() - 1) + z;
        if (m_historia_u.size() >= 2 + m_opoznienie && m_historia_y.size() >= 2)
        {
            wynik += m_b_2 * m_historia_u.at(m_historia_u.size() - 2 - m_opoznienie) - m_a_2 * m_historia_y.at(m_historia_y.size() - 2);
            if (m_historia_u.size() >= 3 + m_opoznienie && m_historia_y.size() >= 3)
            {
                wynik += m_b_3 * m_historia_u.at(m_historia_u.size() - 3 - m_opoznienie) - m_a_3 * m_historia_y.at(m_historia_y.size() - 3);
            }
        }
    }
    else
    {
        wynik = 0.0;
    }
    m_historia_u.push_back(nowe_u);
    m_historia_y.push_back(wynik);
    return wynik;
}

/* Zwraca poprzedni zapamiętany wynik.
 */
double ARX::get_poprz_y()
{
    if (m_historia_y.size() == 0) return 0.0;
    return m_historia_y.at(m_historia_y.size() - 1);
}

/* Do ustawiania wszystkich 3 pozycji werktora A.
 */
void ARX::set_a(double a1, double a2, double a3)
{
    m_a = a1;
    m_a_2 = a2;
    m_a_3 = a3;
}

/* Do ustawiania wszystkich 3 pozycji wektora B.
 */
void ARX::set_b(double b1, double b2, double b3)
{
    m_b = b1;
    m_b_2 = b2;
    m_b_3 = b3;
}

/* Setter opóźnienia.
 */
void ARX::set_opoznienie(int wartosc)
{
    m_opoznienie = wartosc;
}
