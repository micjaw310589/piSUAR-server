#include "wartosczadana.h"
// #include "qdebug.h"

#include <cmath>

WartoscZadana::WartoscZadana(TypWartosciZadanej nowe_typ,
                             double nowe_a,
                             int nowe_t,
                             double nowe_p = 0.0)
    : m_typ_wartosci_zadanej(nowe_typ)
    , m_a(nowe_a)
    , m_t(nowe_t)
    , m_p(nowe_p) // Używamy predrostka nowe, bo samo p kolidowało z jakąś nazwą z QT
{}

/* Do zmieniania zadanego sygnału.
 */
void WartoscZadana::zmien_sygnal(TypWartosciZadanej nowy_typ,
                                 double nowe_a,
                                 int nowe_t,
                                 double nowe_p = 0.0)
{
    m_typ_wartosci_zadanej = nowy_typ;
    m_a = nowe_a;
    m_t = nowe_t;
    m_p = nowe_p;
}

/* Do wyliczania sygnału na bazie zadanej wartości.
 */
double WartoscZadana::generuj(int i)
{
    switch (m_typ_wartosci_zadanej) {
    default:
    case TypWartosciZadanej::SkokJednostkowy: {
        if (i >= m_t)
            return m_a;
        else
            return 0.0;
        break;
    }
    case TypWartosciZadanej::Sinusoida: {
        // qInfo() << std::sin(i);
        if (m_t == 0.0)
            return 0.0; // Nie dzielimy przez 0
        return m_a * std::sin(fmod(i, m_t) / (m_t) * 2 * 3.14);
        break;
    }
    case TypWartosciZadanej::SygnalProstokatny: {
        if (fmod(i, m_t) < m_p * m_t)
            return m_a;
        else
            return 0.0;
        break;
    }
    }
    return 0.0;
}
