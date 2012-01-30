#include <QtCore/QCoreApplication>
#include <QtGui/QApplication>
#include <QtGui>
#include <QtWebKit>
#include "webpage.h"
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    webpage wp(QUrl("http://google.com"));

    return a.exec();
}
