QT += core
QT -= gui

TARGET = QTFILES
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    scientist.cpp \
    controller.cpp \
    model.cpp \
    view.cpp

HEADERS += \
    scientist.h \
    controller.h \
    model.h \
    view.h

DISTFILES +=

