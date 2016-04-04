TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

INCLUDEPATH += -I/usr/local/include
LIBS += -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system
