/********************************************************************************
** Form generated from reading UI file 'dialogarx.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGARX_H
#define UI_DIALOGARX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogARX
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *a1;
    QLabel *label_3;
    QDoubleSpinBox *a2;
    QLabel *label_4;
    QDoubleSpinBox *a3;
    QLabel *label_2;
    QDoubleSpinBox *b1;
    QLabel *label_5;
    QDoubleSpinBox *b2;
    QLabel *label_6;
    QDoubleSpinBox *b3;
    QLabel *label_7;
    QSpinBox *opoznienie;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *DialogARX)
    {
        if (DialogARX->objectName().isEmpty())
            DialogARX->setObjectName("DialogARX");
        DialogARX->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogARX);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(DialogARX);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        a1 = new QDoubleSpinBox(DialogARX);
        a1->setObjectName("a1");
        a1->setMinimum(-99.000000000000000);
        a1->setSingleStep(0.100000000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, a1);

        label_3 = new QLabel(DialogARX);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        a2 = new QDoubleSpinBox(DialogARX);
        a2->setObjectName("a2");
        a2->setMinimum(-99.000000000000000);
        a2->setSingleStep(0.100000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, a2);

        label_4 = new QLabel(DialogARX);
        label_4->setObjectName("label_4");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        a3 = new QDoubleSpinBox(DialogARX);
        a3->setObjectName("a3");
        a3->setMinimum(-99.000000000000000);
        a3->setSingleStep(0.100000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, a3);

        label_2 = new QLabel(DialogARX);
        label_2->setObjectName("label_2");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        b1 = new QDoubleSpinBox(DialogARX);
        b1->setObjectName("b1");
        b1->setMinimum(-99.000000000000000);
        b1->setSingleStep(0.100000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, b1);

        label_5 = new QLabel(DialogARX);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        b2 = new QDoubleSpinBox(DialogARX);
        b2->setObjectName("b2");
        b2->setMinimum(-99.000000000000000);
        b2->setSingleStep(0.100000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, b2);

        label_6 = new QLabel(DialogARX);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        b3 = new QDoubleSpinBox(DialogARX);
        b3->setObjectName("b3");
        b3->setMinimum(-99.000000000000000);
        b3->setSingleStep(0.100000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, b3);

        label_7 = new QLabel(DialogARX);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        opoznienie = new QSpinBox(DialogARX);
        opoznienie->setObjectName("opoznienie");
        opoznienie->setMinimum(1);
        opoznienie->setMaximum(3);

        formLayout->setWidget(6, QFormLayout::FieldRole, opoznienie);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(DialogARX);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 6);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        retranslateUi(DialogARX);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogARX, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogARX, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogARX);
    } // setupUi

    void retranslateUi(QDialog *DialogARX)
    {
        DialogARX->setWindowTitle(QCoreApplication::translate("DialogARX", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogARX", "A1", nullptr));
        label_3->setText(QCoreApplication::translate("DialogARX", "A2", nullptr));
        label_4->setText(QCoreApplication::translate("DialogARX", "A3", nullptr));
        label_2->setText(QCoreApplication::translate("DialogARX", "B1", nullptr));
        label_5->setText(QCoreApplication::translate("DialogARX", "B2", nullptr));
        label_6->setText(QCoreApplication::translate("DialogARX", "B3", nullptr));
        label_7->setText(QCoreApplication::translate("DialogARX", "Op\303\263\305\274nienie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogARX: public Ui_DialogARX {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGARX_H
