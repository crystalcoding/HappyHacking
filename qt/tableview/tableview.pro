#-------------------------------------------------
#
# Project created by QtCreator 2015-05-01T22:40:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tableview
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    delegate.cpp

HEADERS  += dialog.h \
    delegate.h

FORMS    += dialog.ui
