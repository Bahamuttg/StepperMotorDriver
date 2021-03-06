#-------------------------------------------------
#
# Project created by QtCreator 2016-07-14T18:54:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RepRap
TEMPLATE = app

LIBS += -L/usr/local/include -lwiringPi

SOURCES += main.cpp\
        mainwindow.cpp \
    steppermotor.cpp \
    coildialog.cpp

HEADERS  += mainwindow.h \
    steppermotor.h \
    motorworker.h \
    coildialog.h

FORMS    += mainwindow.ui \
    coildialog.ui

RESOURCES += \
    Resources/Resources.qrc
