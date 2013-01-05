#-------------------------------------------------
#
# Project created by QtCreator 2012-12-28T16:33:00
#
#-------------------------------------------------

QT       += core gui

TARGET = UtilitiesTestApp
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

INCLUDEPATH += $${PWD}/../../Utilities

DEPENDPATH += $${PWD}/../../Utilities

DESTDIR = $${PWD}/../../../bin/$${BUILDTYPE}/

LIBS += -L$${PWD}/../../../bin/$${BUILDTYPE}/ -lUtilities

