#include "zaklocenia.h"

#include <random>

Zaklocenia::Zaklocenia(double srednia, double odchylenie)
    : m_srednia(srednia), m_odchylenie(odchylenie)
{}

/* Generuje zakłócenia w rozkładzie naturalnym, na bazie zadanego zakresu.
 */
double Zaklocenia::generuj(int _)
{
    if (m_odchylenie == 0.0) return 0.0;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> dis{m_srednia, m_odchylenie};
    return dis(gen);
}

/* Settery i gettery
 */
void Zaklocenia::set_srednia(double srednia) { m_srednia = srednia; }
void Zaklocenia::set_odchylenie(double odchylenie) { m_odchylenie = odchylenie; }
