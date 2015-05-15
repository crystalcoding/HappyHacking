#-------------------------------------------------
#
# Project created by QtCreator 2015-05-14T21:26:31
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = wt
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

LIBS += -lwt -lwthttp -lboost_signals
QMAKE_CXXFLAGS += -DNDEBUG
