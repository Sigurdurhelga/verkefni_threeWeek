QT += core
QT += sql
QT -= gui

TARGET = QTFILES
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Controller.cpp \
    Model.cpp \
    Scientist.cpp \
    View.cpp

HEADERS += \
    Controller.h \
    Model.h \
    Scientist.h \
    View.h

DISTFILES +=

