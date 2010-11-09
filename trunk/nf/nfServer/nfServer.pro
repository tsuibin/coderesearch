#-------------------------------------------------
#
# Project created by QtCreator 2010-07-09T18:25:57
#
#-------------------------------------------------

QT       += core gui network

#QT       += gui

TARGET = nfServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    nfserver.cpp \
    clientthread.cpp

HEADERS += \
    nfserver.h \
    clientthread.h
