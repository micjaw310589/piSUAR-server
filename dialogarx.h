#ifndef DIALOGARX_H
#define DIALOGARX_H

#include <QDialog>

namespace Ui {
class DialogARX;
}

class DialogARX : public QDialog
{
    Q_OBJECT

public:
    explicit DialogARX(QWidget *parent = nullptr);
    ~DialogARX();
    void get_wartosci(double& a1, double& a2, double& a3, double& b1, double& b2, double& b3, int& opoznienie);
    void set_wartosci(double a1, double a2, double a3, double b1, double b2, double b3, int opoznienie);

private:
    Ui::DialogARX *ui;
};

#endif // DIALOGARX_H
