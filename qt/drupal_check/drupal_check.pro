#-------------------------------------------------
#
# Project created by QtCreator 2015-05-16T00:43:43
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drupal_check
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    site.cpp

HEADERS  += mainwindow.h \
    site.h

FORMS    += mainwindow.ui
