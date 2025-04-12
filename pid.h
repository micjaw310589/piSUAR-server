#ifndef PID_H
#define PID_H

#include <vector>

class PID
{
private:
    // Parametry
    double m_k;
    double m_ti;
    double m_td;
    // Spamiętywanie
    std::vector<double> m_historia_uchybow;
    double m_poprz_p;
    double m_poprz_i;
    double m_poprz_d;
    bool m_sposob_wyliczania_calki;

public:
    PID(double, double, double);
    double P();
    double I();
    double D();
    double operator()(double);
    void zmien_wspolczynniki(double, double, double);
    double get_poprz_p();
    double get_poprz_i();
    double get_poprz_d();
    void zeruj_calke();
    void set_sposob_wyliczania_calki(bool);
};

#endif // PID_H
