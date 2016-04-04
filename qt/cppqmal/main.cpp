#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>
#include <QUrl>
#include <QQmlContext>


#include <QStandardPaths>
#include <QStringList>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QUrl appPath(QString("%1").arg(app.applicationDirPath()));
    qDebug() << "This is where the application lives " << appPath;
    engine.rootContext()->setContextProperty("appPath", appPath);

    QUrl moviesPath;
    const QStringList moviesLocation = QStandardPaths::standardLocations(QStandardPaths::MoviesLocation);

    if (moviesLocation.isEmpty()){
        moviesPath = appPath.resolved(QUrl("/home/bps"));
    } else {
        moviesPath = QString("%1").arg(moviesLocation.first());
    }

    engine.rootContext()->setContextProperty("moviesPath", moviesPath);


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
