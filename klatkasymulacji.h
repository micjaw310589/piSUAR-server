#ifndef KLATKASYMULACJI_H
#define KLATKASYMULACJI_H

#include <functional>

class KlatkaSymulacji
{
private:
    double m_w;
    double m_z;
    double m_e;
    double m_u;
    double m_y;
    double m_p;
    double m_i;
    double m_d;

public:
    KlatkaSymulacji(double, double, double, double, double, double, double, double);
    KlatkaSymulacji();

    double get_w() const;
    void set_w(double);
    double get_z() const;
    void set_z(double);
    double get_e() const;
    void set_e(double);
    double get_u() const;
    void set_u(double);
    double get_y() const;
    void set_y(double);
    double get_p() const;
    void set_p(double);
    double get_i() const;
    void set_i(double);
    double get_d() const;
    void set_d(double);
};

#endif // KLATKASYMULACJI_H
