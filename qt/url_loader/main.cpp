#include <QtGui/QApplication>
#include "dialog.h"

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog *w = new Dialog();
    w->show();

    return a.exec();
}
