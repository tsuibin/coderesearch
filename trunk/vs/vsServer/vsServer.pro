######################################################################
# AKA Video Chat Project 2010
######################################################################
QT       += core gui network
TEMPLATE = app
TARGET = 
DEPENDPATH += .
LIBS += -lcv -lhighgui

SOURCES += main.cpp QOpenCVWidget.cpp MyCameraWindow.cpp
HEADERS += QOpenCVWidget.h MyCameraWindow.h

