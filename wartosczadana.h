#ifndef WARTOSCZADANA_H
#define WARTOSCZADANA_H

#include "generator.h"

enum class TypWartosciZadanej { SkokJednostkowy, Sinusoida, SygnalProstokatny };

class WartoscZadana : public Generator
{
private:
    TypWartosciZadanej m_typ_wartosci_zadanej;
    double m_a;
    int m_t;
    double m_p;

public:
    WartoscZadana(TypWartosciZadanej, double, int, double);
    void zmien_sygnal(TypWartosciZadanej, double, int, double);
    double generuj(int);
};

#endif // WARTOSCZADANA_H
