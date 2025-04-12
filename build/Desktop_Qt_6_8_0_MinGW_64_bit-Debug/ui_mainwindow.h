/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_8;
    QFrame *verticalFrame1;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_6;
    QFormLayout *formLayout_3;
    QDoubleSpinBox *wartoscZadanaA;
    QSpinBox *wartoscZadanaT;
    QLabel *label_2;
    QLabel *label_4;
    QDoubleSpinBox *wartoscZadanaP;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *sygnalSkokowy;
    QRadioButton *sygnalSinusoida;
    QRadioButton *sygnalProstakat;
    QLabel *label_7;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_20;
    QFormLayout *formLayout_4;
    QLabel *label_16;
    QLabel *label_18;
    QDoubleSpinBox *zaklocenie_sred;
    QDoubleSpinBox *zaklocenie_odchylenie;
    QFrame *verticalFrame3;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_8;
    QFormLayout *formLayout_2;
    QLabel *label_9;
    QDoubleSpinBox *pidK;
    QLabel *label_11;
    QDoubleSpinBox *pidTd;
    QDoubleSpinBox *pidTi;
    QLabel *label_10;
    QPushButton *zeruj_czesc_calkujaca;
    QCheckBox *sposob_wyliczania_calki;
    QLabel *label_17;
    QFrame *verticalFrame2;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *zmien_ustawienia_arx;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *opoznienie;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_18;
    QDoubleSpinBox *arx_a;
    QDoubleSpinBox *arx_a_2;
    QDoubleSpinBox *arx_a_3;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_19;
    QDoubleSpinBox *arx_b;
    QDoubleSpinBox *arx_b_2;
    QDoubleSpinBox *arx_b_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *wykres;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_14;
    QSpinBox *interwal;
    QPushButton *updateButton;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QSpacerItem *horizontalSpacer_32;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 240, 651));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalFrame1 = new QFrame(scrollAreaWidgetContents);
        verticalFrame1->setObjectName("verticalFrame1");
        verticalFrame1->setFrameShape(QFrame::Shape::StyledPanel);
        verticalLayout_7 = new QVBoxLayout(verticalFrame1);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label_8 = new QLabel(verticalFrame1);
        label_8->setObjectName("label_8");

        horizontalLayout_2->addWidget(label_8);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_7->addLayout(horizontalLayout_2);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        wartoscZadanaA = new QDoubleSpinBox(verticalFrame1);
        wartoscZadanaA->setObjectName("wartoscZadanaA");
        wartoscZadanaA->setMinimum(-100.000000000000000);
        wartoscZadanaA->setMaximum(1000.000000000000000);
        wartoscZadanaA->setValue(15.000000000000000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, wartoscZadanaA);

        wartoscZadanaT = new QSpinBox(verticalFrame1);
        wartoscZadanaT->setObjectName("wartoscZadanaT");
        wartoscZadanaT->setMinimum(1);
        wartoscZadanaT->setMaximum(1000);
        wartoscZadanaT->setValue(25);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, wartoscZadanaT);

        label_2 = new QLabel(verticalFrame1);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_2);

        label_4 = new QLabel(verticalFrame1);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_4);

        wartoscZadanaP = new QDoubleSpinBox(verticalFrame1);
        wartoscZadanaP->setObjectName("wartoscZadanaP");
        wartoscZadanaP->setMaximum(1.000000000000000);
        wartoscZadanaP->setSingleStep(0.010000000000000);
        wartoscZadanaP->setValue(0.500000000000000);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, wartoscZadanaP);

        label_5 = new QLabel(verticalFrame1);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        sygnalSkokowy = new QRadioButton(verticalFrame1);
        sygnalSkokowy->setObjectName("sygnalSkokowy");
        sygnalSkokowy->setChecked(false);

        verticalLayout_2->addWidget(sygnalSkokowy);

        sygnalSinusoida = new QRadioButton(verticalFrame1);
        sygnalSinusoida->setObjectName("sygnalSinusoida");
        sygnalSinusoida->setChecked(true);

        verticalLayout_2->addWidget(sygnalSinusoida);

        sygnalProstakat = new QRadioButton(verticalFrame1);
        sygnalProstakat->setObjectName("sygnalProstakat");

        verticalLayout_2->addWidget(sygnalProstakat);


        formLayout_3->setLayout(3, QFormLayout::FieldRole, verticalLayout_2);

        label_7 = new QLabel(verticalFrame1);
        label_7->setObjectName("label_7");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_7);


        verticalLayout_7->addLayout(formLayout_3);


        verticalLayout_8->addWidget(verticalFrame1);

        verticalFrame = new QFrame(scrollAreaWidgetContents);
        verticalFrame->setObjectName("verticalFrame");
        verticalFrame->setFrameShape(QFrame::Shape::StyledPanel);
        verticalLayout_10 = new QVBoxLayout(verticalFrame);
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_19);

        label_15 = new QLabel(verticalFrame);
        label_15->setObjectName("label_15");

        horizontalLayout_7->addWidget(label_15);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_20);


        verticalLayout_10->addLayout(horizontalLayout_7);

        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        label_16 = new QLabel(verticalFrame);
        label_16->setObjectName("label_16");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_16);

        label_18 = new QLabel(verticalFrame);
        label_18->setObjectName("label_18");

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_18);

        zaklocenie_sred = new QDoubleSpinBox(verticalFrame);
        zaklocenie_sred->setObjectName("zaklocenie_sred");
        zaklocenie_sred->setMinimum(-99.000000000000000);
        zaklocenie_sred->setSingleStep(0.100000000000000);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, zaklocenie_sred);

        zaklocenie_odchylenie = new QDoubleSpinBox(verticalFrame);
        zaklocenie_odchylenie->setObjectName("zaklocenie_odchylenie");
        zaklocenie_odchylenie->setMinimum(0.000000000000000);
        zaklocenie_odchylenie->setSingleStep(0.010000000000000);
        zaklocenie_odchylenie->setValue(0.100000000000000);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, zaklocenie_odchylenie);


        verticalLayout_10->addLayout(formLayout_4);


        verticalLayout_8->addWidget(verticalFrame);

        verticalFrame3 = new QFrame(scrollAreaWidgetContents);
        verticalFrame3->setObjectName("verticalFrame3");
        verticalFrame3->setFrameShape(QFrame::Shape::StyledPanel);
        verticalLayout_6 = new QVBoxLayout(verticalFrame3);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label_12 = new QLabel(verticalFrame3);
        label_12->setObjectName("label_12");

        horizontalLayout_4->addWidget(label_12);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout_6->addLayout(horizontalLayout_4);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_9 = new QLabel(verticalFrame3);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_9);

        pidK = new QDoubleSpinBox(verticalFrame3);
        pidK->setObjectName("pidK");
        pidK->setValue(0.300000000000000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pidK);

        label_11 = new QLabel(verticalFrame3);
        label_11->setObjectName("label_11");
        label_11->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_11);

        pidTd = new QDoubleSpinBox(verticalFrame3);
        pidTd->setObjectName("pidTd");
        pidTd->setSingleStep(0.010000000000000);
        pidTd->setValue(0.100000000000000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pidTd);

        pidTi = new QDoubleSpinBox(verticalFrame3);
        pidTi->setObjectName("pidTi");
        pidTi->setMaximum(300.000000000000000);
        pidTi->setValue(10.000000000000000);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pidTi);

        label_10 = new QLabel(verticalFrame3);
        label_10->setObjectName("label_10");
        label_10->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_10);

        zeruj_czesc_calkujaca = new QPushButton(verticalFrame3);
        zeruj_czesc_calkujaca->setObjectName("zeruj_czesc_calkujaca");

        formLayout_2->setWidget(4, QFormLayout::FieldRole, zeruj_czesc_calkujaca);

        sposob_wyliczania_calki = new QCheckBox(verticalFrame3);
        sposob_wyliczania_calki->setObjectName("sposob_wyliczania_calki");

        formLayout_2->setWidget(3, QFormLayout::FieldRole, sposob_wyliczania_calki);

        label_17 = new QLabel(verticalFrame3);
        label_17->setObjectName("label_17");

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_17);


        verticalLayout_6->addLayout(formLayout_2);


        verticalLayout_8->addWidget(verticalFrame3);

        verticalFrame2 = new QFrame(scrollAreaWidgetContents);
        verticalFrame2->setObjectName("verticalFrame2");
        verticalFrame2->setFrameShape(QFrame::Shape::StyledPanel);
        verticalLayout_9 = new QVBoxLayout(verticalFrame2);
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        label_13 = new QLabel(verticalFrame2);
        label_13->setObjectName("label_13");

        horizontalLayout_5->addWidget(label_13);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        verticalLayout_9->addLayout(horizontalLayout_5);

        zmien_ustawienia_arx = new QPushButton(verticalFrame2);
        zmien_ustawienia_arx->setObjectName("zmien_ustawienia_arx");

        verticalLayout_9->addWidget(zmien_ustawienia_arx);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(verticalFrame2);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        opoznienie = new QSpinBox(verticalFrame2);
        opoznienie->setObjectName("opoznienie");
        opoznienie->setEnabled(false);
        opoznienie->setMinimum(1);
        opoznienie->setMaximum(3);

        formLayout->setWidget(0, QFormLayout::FieldRole, opoznienie);

        label_3 = new QLabel(verticalFrame2);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        arx_a = new QDoubleSpinBox(verticalFrame2);
        arx_a->setObjectName("arx_a");
        arx_a->setEnabled(false);
        arx_a->setMinimum(-99.000000000000000);
        arx_a->setValue(-0.400000000000000);

        horizontalLayout_18->addWidget(arx_a);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_18);

        arx_a_2 = new QDoubleSpinBox(verticalFrame2);
        arx_a_2->setObjectName("arx_a_2");
        arx_a_2->setEnabled(false);
        arx_a_2->setMinimum(-99.000000000000000);
        arx_a_2->setSingleStep(0.100000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, arx_a_2);

        arx_a_3 = new QDoubleSpinBox(verticalFrame2);
        arx_a_3->setObjectName("arx_a_3");
        arx_a_3->setEnabled(false);
        arx_a_3->setMinimum(-99.000000000000000);
        arx_a_3->setSingleStep(0.100000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, arx_a_3);

        label_6 = new QLabel(verticalFrame2);
        label_6->setObjectName("label_6");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        arx_b = new QDoubleSpinBox(verticalFrame2);
        arx_b->setObjectName("arx_b");
        arx_b->setEnabled(false);
        arx_b->setMinimum(-99.000000000000000);
        arx_b->setValue(0.600000000000000);

        horizontalLayout_19->addWidget(arx_b);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_19);

        arx_b_2 = new QDoubleSpinBox(verticalFrame2);
        arx_b_2->setObjectName("arx_b_2");
        arx_b_2->setEnabled(false);
        arx_b_2->setMinimum(-99.000000000000000);
        arx_b_2->setSingleStep(0.100000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, arx_b_2);

        arx_b_3 = new QDoubleSpinBox(verticalFrame2);
        arx_b_3->setObjectName("arx_b_3");
        arx_b_3->setEnabled(false);
        arx_b_3->setMinimum(-99.000000000000000);
        arx_b_3->setSingleStep(0.100000000000000);

        formLayout->setWidget(6, QFormLayout::FieldRole, arx_b_3);


        verticalLayout_9->addLayout(formLayout);


        verticalLayout_8->addWidget(verticalFrame2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        wykres = new QLabel(centralwidget);
        wykres->setObjectName("wykres");
        wykres->setLayoutDirection(Qt::LayoutDirection::RightToLeft);

        verticalLayout_3->addWidget(wykres);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");

        horizontalLayout_3->addWidget(label_14);

        interwal = new QSpinBox(centralwidget);
        interwal->setObjectName("interwal");
        interwal->setMinimum(100);
        interwal->setMaximum(2000);
        interwal->setSingleStep(25);

        horizontalLayout_3->addWidget(interwal);

        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName("updateButton");

        horizontalLayout_3->addWidget(updateButton);

        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");

        horizontalLayout_3->addWidget(startButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");

        horizontalLayout_3->addWidget(stopButton);

        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName("resetButton");

        horizontalLayout_3->addWidget(resetButton);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_32);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        horizontalLayout_3->addWidget(saveButton);

        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");

        horizontalLayout_3->addWidget(loadButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalLayout_4->setStretch(0, 6);
        verticalLayout_4->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Symulator", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Warto\305\233\304\207 Zadana", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "T", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "P", nullptr));
        sygnalSkokowy->setText(QCoreApplication::translate("MainWindow", "Skok Jednostkowy", nullptr));
        sygnalSinusoida->setText(QCoreApplication::translate("MainWindow", "Sinusoida", nullptr));
        sygnalProstakat->setText(QCoreApplication::translate("MainWindow", "Sygna\305\202 Porstok\304\205tny", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Sygna\305\202", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Zak\305\202\303\263cenia", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\305\233rednia u", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "odchylenie std", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "PID", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Td", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Ti", nullptr));
        zeruj_czesc_calkujaca->setText(QCoreApplication::translate("MainWindow", "Zeruj cz\304\231\305\233\304\207 ca\305\202kuj\304\205c\304\205", nullptr));
        sposob_wyliczania_calki->setText(QCoreApplication::translate("MainWindow", "Sumowanie przed ca\305\202k\304\205", nullptr));
        label_17->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "ARX", nullptr));
        zmien_ustawienia_arx->setText(QCoreApplication::translate("MainWindow", "Zmien ustawienia ARX", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Op\303\263\305\272nienie:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        wykres->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "Interwa\305\202:", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "Aktualizuj Dane", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Zapisz", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Wczytaj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
