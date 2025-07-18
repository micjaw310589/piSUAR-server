QT       += core gui charts network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arx.cpp \
    dialog.cpp \
    dialogarx.cpp \
    frametoclient.cpp \
    frametoserver.cpp \
    generator.cpp \
    klatkasymulacji.cpp \
    main.cpp \
    mainwindow.cpp \
    pid.cpp \
    symulacja.cpp \
    wartosczadana.cpp \
    zaklocenia.cpp

HEADERS += \
    arx.h \
    dialog.h \
    dialogarx.h \
    frametoclient.h \
    frametoserver.h \
    generator.h \
    klatkasymulacji.h \
    mainwindow.h \
    pid.h \
    symulacja.h \
    wartosczadana.h \
    zaklocenia.h

FORMS += \
    dialog.ui \
    dialogarx.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
