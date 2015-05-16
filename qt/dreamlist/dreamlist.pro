#-------------------------------------------------
#
# Project created by QtCreator 2015-05-15T22:31:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dreamlist
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /home/bps/Downloads/mongo-cxx-driver/build/install/include
LIBS += -L/home/bps/Downloads/mongo-cxx-driver/build/install/lib -lmongoclient -lboost_system -pthread -lboost_thread -lboost_regex -lssl -lcrypto
