TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
QT += network
HEADERS += manachatclient.h manachatserver.h \
    manacollector.h
SOURCES += main.cpp manachatclient.cpp manachatserver.cpp \
    manacollector.cpp
