#include <QtGui/QApplication>
#include "politic.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    politic w;
    w.show();
    return a.exec();
}
