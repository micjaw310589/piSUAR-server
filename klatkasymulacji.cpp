#include "klatkasymulacji.h"

KlatkaSymulacji::KlatkaSymulacji(double w_zadana,
                                 double e_uchyb,
                                 double u_sterujacy,
                                 double y_sprzezenie,
                                 double zaklocenia,
                                 double nowe_p,
                                 double nowe_i,
                                 double nowe_d)
    : m_w(w_zadana)
    , m_z(zaklocenia)
    , m_e(e_uchyb)
    , m_u(u_sterujacy)
    , m_y(y_sprzezenie)
    , m_p(nowe_p)
    , m_i(nowe_i)
    , m_d(nowe_d)
{}


/* Settery i gettery.
 * Nie ma większej filozofii.
 * Pobierają i ustawiają.
 */
double KlatkaSymulacji::get_w()
{
    return m_w;
}
void KlatkaSymulacji::set_w(double wartosc)
{
    m_w = wartosc;
}
double KlatkaSymulacji::get_z()
{
    return m_z;
}
void KlatkaSymulacji::set_z(double wartosc)
{
    m_z = wartosc;
}
double KlatkaSymulacji::get_e()
{
    return m_e;
}
void KlatkaSymulacji::set_e(double wartosc)
{
    m_e = wartosc;
}
double KlatkaSymulacji::get_u()
{
    return m_u;
}
void KlatkaSymulacji::set_u(double wartosc)
{
    m_u = wartosc;
}
double KlatkaSymulacji::get_y()
{
    return m_y;
}
void KlatkaSymulacji::set_y(double wartosc)
{
    m_y = wartosc;
}
double KlatkaSymulacji::get_p()
{
    return m_p;
}
void KlatkaSymulacji::set_p(double wartosc)
{
    m_p = wartosc;
}
double KlatkaSymulacji::get_i()
{
    return m_i;
}
void KlatkaSymulacji::set_i(double wartosc)
{
    m_i = wartosc;
}
double KlatkaSymulacji::get_d()
{
    return m_d;
}
void KlatkaSymulacji::set_d(double wartosc)
{
    m_d = wartosc;
}
