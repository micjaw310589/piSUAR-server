#ifndef KLATKASYMULACJI_H
#define KLATKASYMULACJI_H

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

    double get_w();
    void set_w(double);
    double get_z();
    void set_z(double);
    double get_e();
    void set_e(double);
    double get_u();
    void set_u(double);
    double get_y();
    void set_y(double);
    double get_p();
    void set_p(double);
    double get_i();
    void set_i(double);
    double get_d();
    void set_d(double);
};

#endif // KLATKASYMULACJI_H
