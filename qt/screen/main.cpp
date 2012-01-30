#include <QtGui/QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include "mainwindow.h"
#include <iostream>
int main(int argc, char *argv[])
{
    using namespace std;
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QDesktopWidget *d = QApplication::desktop();
    qDebug() << d->width();
    qDebug() << d->height();
    qDebug() << d->size();
    return a.exec();
}
