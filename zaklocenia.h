#ifndef ZAKLOCENIA_H
#define ZAKLOCENIA_H

#include "generator.h"

class Zaklocenia : public Generator
{
private:
    double m_srednia;
    double m_odchylenie;
public:
    Zaklocenia(double srednia, double odchylenie);
    double generuj(int);
    void set_srednia(double);
    void set_odchylenie(double);
};

#endif // ZAKLOCENIA_H
