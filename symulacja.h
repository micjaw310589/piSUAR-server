#ifndef SYMULACJA_H
#define SYMULACJA_H

#include "arx.h"
#include "klatkasymulacji.h"
#include "pid.h"
#include "wartosczadana.h"
#include "zaklocenia.h"
#include <list>

class Symulacja
{
private:
    std::list<KlatkaSymulacji> m_klatki_symulacji;
    PID m_pid;
    ARX m_arx;
    WartoscZadana m_wartosc_zadana;
    Zaklocenia m_zaklocenia;
    int m_i;
    // int m_opoznienie;
public:
    Symulacja();
    void nastepna_klatka();

    std::list<KlatkaSymulacji> *get_klatki_symulacji();
    void set_klatki_symulacji(std::list<KlatkaSymulacji>);
    PID *get_pid();
    ARX *get_arx();
    WartoscZadana *get_wartosc_zadana();
    // Zaklocenia* get_zaklocenia();
    void set_i(int);
    void set_opoznienie(int);
    void set_zaklocenia(double srednia, double odchylenie);
};

#endif // SYMULACJA_H
