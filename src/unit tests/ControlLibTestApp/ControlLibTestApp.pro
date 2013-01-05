#-------------------------------------------------
#
# Project created by QtCreator 2012-12-30T20:59:50
#
#-------------------------------------------------

QT       += core gui

TARGET = ControlLibTestApp
TEMPLATE = app

CONFIG(debug, debug|release) {
     BUILDTYPE = 'debug'
 } else {
     BUILDTYPE = 'release'
 }


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += $${PWD}/../../interfaces\
        $${PWD}/../../ControlLib

DEPENDPATH += $${PWD}/../../interfaces\
        $${PWD}/../../ControlLib

DESTDIR = $${PWD}/../../../bin/$${BUILDTYPE}/

LIBS += -L$${PWD}/../../../bin/$${BUILDTYPE}/ -lControlLib

