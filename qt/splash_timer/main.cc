#include <QApplication>
#include <QPushButton>
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton hello("Updating report...");
    QPixmap pixmap(":/images/gnome.png");
    QSplashScreen splash(pixmap);
    splash.show();
    hello.resize(100, 30);
    hello.show();

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), &app, SLOT(quit()));
    timer->start(5000);
    
    return app.exec();
}
