#-------------------------------------------------
#
# Project created by QtCreator 2012-11-10T12:09:23
#
#-------------------------------------------------

QT       -= gui

CONFIG(debug, debug|release) {
     BUILDTYPE = 'debug'
 } else {
     BUILDTYPE = 'release'
 }

DESTDIR = $${PWD}/../../bin/$${BUILDTYPE}/

TARGET = Utilities
TEMPLATE = lib

DEFINES += UTILITIES_LIBRARY

SOURCES += \
    csv/csvwriter.cpp \
    csv/csvreader.cpp \
    logger.cpp

HEADERS +=\
        Utilities_global.h \
    csv/csvwriter.h \
    csv/csvreader.h \
    csv/CSVcommon.h \
    logger.h \
    orderedhash.h
