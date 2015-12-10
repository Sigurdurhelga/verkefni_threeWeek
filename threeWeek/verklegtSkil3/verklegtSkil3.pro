#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T11:45:27
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = verklegtSkil3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        Controller.cpp\
        Model.cpp\
        Computers.cpp\
        Scientist.cpp\

HEADERS  += mainwindow.h\
            Controller.h\
            Model.h\
            Computers.h\
            Scientist.h

FORMS    += mainwindow.ui
