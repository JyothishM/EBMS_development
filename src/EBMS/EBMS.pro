#-------------------------------------------------
#
# Project created by QtCreator 2012-12-26T12:34:15
#
#-------------------------------------------------

QT       += core gui

TARGET = EBMS
TEMPLATE = app

CONFIG(debug, debug|release) {
     BUILDTYPE = 'debug'
 } else {
     BUILDTYPE = 'release'
 }


SOURCES += main.cpp\
        ebmsui.cpp \
    oplistscreenui.cpp

HEADERS  += ebmsui.h \
    oplistscreenui.h

FORMS    += ebmsui.ui \
    oplistscreenui.ui

INCLUDEPATH += $${PWD}/../interfaces\
                $${PWD}/../EBMScore\
                $${PWD}/../Utilities\

DEPENDPATH += $${PWD}/../interfaces\
                $${PWD}/../EBMScore\
                $${PWD}/../Utilities


DESTDIR = $${PWD}/../../bin/$${BUILDTYPE}/

LIBS += -L$${PWD}/../../bin/$${BUILDTYPE}/ -lEBMScore\
        -L$${PWD}/../../bin/$${BUILDTYPE}/ -lUtilities
