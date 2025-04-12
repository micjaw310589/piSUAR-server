#include "dialogarx.h"
#include "ui_dialogarx.h"

DialogARX::DialogARX(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogARX)
{
    ui->setupUi(this);
}

DialogARX::~DialogARX()
{
    delete ui;
}

/* Getter wartości z dialogu ARX
 */
void DialogARX::get_wartosci(double& a1, double& a2, double& a3, double& b1, double& b2, double& b3, int& opoznienie)
{
    a1 = ui->a1->value();
    a2 = ui->a2->value();
    a3 = ui->a3->value();
    b1 = ui->b1->value();
    b2 = ui->b2->value();
    b3 = ui->b3->value();
    opoznienie = ui->opoznienie->value();
}

/* Setter wartości do dialogu ARX
 */
void DialogARX::set_wartosci(double a1, double a2, double a3, double b1, double b2, double b3, int opoznienie)
{
    ui->a1->setValue(a1);
    ui->a2->setValue(a2);
    ui->a3->setValue(a3);
    ui->b1->setValue(b1);
    ui->b2->setValue(b2);
    ui->b3->setValue(b3);
    ui->opoznienie->setValue(opoznienie);
}
