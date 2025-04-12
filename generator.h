#ifndef GENERATOR_H
#define GENERATOR_H

#include "klatkasymulacji.h"
#include <list>

class Generator
{
public:
    Generator();

    double generuj(int);
    double generuj(KlatkaSymulacji);
    double generuj(std::list<KlatkaSymulacji>);
};

#endif // GENERATOR_H
