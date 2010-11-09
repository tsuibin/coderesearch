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
    serverthread.cpp \
    userthread.cpp \
    videocollector.cpp

HEADERS  += dialog.h \
    qcameradevice.h \
    serverthread.h \
    userthread.h \
    videocollector.h

FORMS    += dialog.ui
