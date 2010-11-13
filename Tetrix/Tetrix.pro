# -------------------------------------------------
# Project created by QtCreator 2009-12-20T17:29:12
# -------------------------------------------------
QT += core gui
TARGET = Tetrix
TEMPLATE = app
SOURCES += main.cpp \
    widget.cpp \
    myitem.cpp \
    gamearea.cpp
HEADERS += widget.h \
    gamearea.h \
    myitem.h
FORMS += widget.ui

CONFIG += mobility
MOBILITY =

symbian {
    TARGET.UID3 = 0xe627c49f
    # TARGET.CAPABILITY +=
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
