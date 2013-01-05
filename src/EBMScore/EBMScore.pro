#-------------------------------------------------
#
# Project created by QtCreator 2012-12-26T11:03:28
#
#-------------------------------------------------

QT       += sql xml

TARGET = EBMScore
TEMPLATE = lib

CONFIG(debug, debug|release) {
     BUILDTYPE = 'debug'
 } else {
     BUILDTYPE = 'release'
 }

DEFINES += EBMSCORE_LIBRARY

SOURCES += ebms.cpp \
    oplistscreen.cpp

HEADERS += ebms.h\
        EBMScore_global.h \
    ebms_common.h \
    oplistscreen.h


INCLUDEPATH += $${PWD}/../interfaces\
                $${PWD}/../Utilities

DEPENDPATH += $${PWD}/../interfaces

DESTDIR = $${PWD}/../../bin/$${BUILDTYPE}/

LIBS += -L$${PWD}/../../bin/$${BUILDTYPE}/ -lUtilities
