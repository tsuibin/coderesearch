#-------------------------------------------------
#
# Project created by QtCreator 2010-11-05T15:33:58
#
#-------------------------------------------------

QT       += core gui network

TARGET = QOpenCV
TEMPLATE = app

unix:LIBS += -lcv \
    -lhighgui

SOURCES += main.cpp\
        dialog.cpp \
    qcameradevice.cpp \
    tcpthread.cpp

HEADERS  += dialog.h \
    qcameradevice.h \
    tcpthread.h

FORMS    += dialog.ui
