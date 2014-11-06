#-------------------------------------------------
#
# Project created by QtCreator 2013-02-10T12:11:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bcd_gui
TEMPLATE = app


SOURCES += main.cpp\
        bcdgui.cpp

HEADERS  += bcdgui.h

FORMS    += bcdgui.ui

QMAKE_CXXFLAGS +=-std=c++0x
