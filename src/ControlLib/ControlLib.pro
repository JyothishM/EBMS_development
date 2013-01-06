#-------------------------------------------------
#
# Project created by QtCreator 2012-12-30T20:30:25
#
#-------------------------------------------------

QT       += xml

CONFIG(debug, debug|release) {
     BUILDTYPE = 'debug'
 } else {
     BUILDTYPE = 'release'
 }

DESTDIR = $${PWD}/../../bin/$${BUILDTYPE}/

TARGET = ControlLib
TEMPLATE = lib

DEFINES += CONTROLLIB_LIBRARY

SOURCES += \
    librarybutton.cpp \
    searchfilterlistview.cpp \
    sortfilterproxymodel.cpp \
    librarydialog.cpp

HEADERS +=\
        ControlLib_global.h \
    librarybutton.h \
    searchfilterlistview.h \
    sortfilterproxymodel.h \
    librarydialog.h

INCLUDEPATH += $${PWD}/../interfaces\
        $${PWD}/../Utilities

DEPENDPATH += $${PWD}/../interfaces\
        $${PWD}/../Utilities

LIBS += -L$${PWD}/../../bin/$${BUILDTYPE}/ -lUtilities

RESOURCES += \
    icons.qrc

FORMS += \
    searchfilterlistview.ui \
    librarydialog.ui
