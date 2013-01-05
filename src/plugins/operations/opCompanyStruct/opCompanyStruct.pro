#-------------------------------------------------
#
# Project created by QtCreator 2012-12-26T15:46:27
#
#-------------------------------------------------

TARGET = opCompanyStruct
TEMPLATE = lib

CONFIG(debug, debug|release) {
     BUILDTYPE = 'debug'
 } else {
     BUILDTYPE = 'release'
 }

DEFINES += OPCOMPANYSTRUCT_LIBRARY

SOURCES += \
    opcompanystructplugin.cpp \
    comstructopdetail.cpp \
    companystructdesigner.cpp

HEADERS +=\
        opCompanyStruct_global.h \
    opcompanystructplugin.h \
    comstructopdetail.h \
    companystructdesigner.h

INCLUDEPATH += $${PWD}/../../../interfaces\
                $${PWD}/../../../EBMScore

DEPENDPATH += $${PWD}/../../../interfaces\
                $${PWD}/../../../EBMScore



DESTDIR = $${PWD}/../../../../bin/$${BUILDTYPE}/plugins/operations/

LIBS += -L$${PWD}/../../../../bin/$${BUILDTYPE}/ -lUtilities

RESOURCES += \
    icons.qrc

FORMS += \
    companystructdesigner.ui
