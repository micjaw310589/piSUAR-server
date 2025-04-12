#ifndef ARX_H
#define ARX_H

#include <vector>

class ARX
{
    double m_a;
    double m_a_2;
    double m_a_3;
    double m_b;
    double m_b_2;
    double m_b_3;
    // double m_poprz_y;
    int m_opoznienie;
    std::vector<double> m_historia_y;

public:
    std::vector<double> m_historia_u;

    ARX(double, double, double, double, double, double, int);
    double operator()(double u,
                      double z); // Dokładnie które wartości będą podane zadecyduje symulacja
    double get_poprz_y();
    void set_a(double, double, double);
    void set_b(double, double, double);
    void set_opoznienie(int);
};

#endif // ARX_H
