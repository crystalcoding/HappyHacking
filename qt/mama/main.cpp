#include <QtGui/QApplication>
#include <QSplashScreen>
#include "mama.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QResource::registerResource("mama.rcc");

    //QIcon titleIcon;
    //titleIcon.addPixmap(QPixmap(QString::fromUtf8(":/chopper.jpg")), QIcon::Normal, QIcon::Off);

    QPixmap pixmap("windows7.jpg");
    QSplashScreen splash(pixmap);
    splash.show();


    QTranslator mamaTranslator;
    QString chFileName = QString("mama_zh_tw.qm");
    mamaTranslator.load(chFileName);
    a.installTranslator(&mamaTranslator);

    Mama w;
    w.show();

    //splash.hide();



    return a.exec();
}
