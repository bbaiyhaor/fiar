#-------------------------------------------------
#
# Project created by QtCreator 2015-09-02T21:01:44
#
#-------------------------------------------------

QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fiar
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        board.cpp \
    fiar.cpp \
    server.cpp \
    tcpsocket.cpp \
    tcpthread.cpp \
    client.cpp

HEADERS  += board.h \
    fiar.h \
    server.h \
    tcpsocket.h \
    tcpthread.h \
    client.h

FORMS    += board.ui
