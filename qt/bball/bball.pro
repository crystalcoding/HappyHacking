#-------------------------------------------------
#
# Project created by QtCreator 2013-02-08T22:40:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bball
TEMPLATE = app


SOURCES += main.cpp\
        bball.cpp \
    team.cpp \
    match.cpp \
    round.cpp \
    division.cpp

HEADERS  += bball.h \
    team.h \
    match.h \
    round.h \
    division.h \
    utils.h

FORMS    += bball.ui

QMAKE_CXXFLAGS +=-std=c++0x
