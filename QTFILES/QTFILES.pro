QT += core
QT += sql
QT -= gui

TARGET = QTFILES
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Scientist.cpp \
    Controller.cpp \
    Model.cpp \
    View.cpp \
    Computers.cpp

HEADERS += \
    Scientist.h \
    Model.h \
    View.h \
    Controller.h \
    Computers.h


DISTFILES +=

