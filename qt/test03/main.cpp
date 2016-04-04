#include <QGuiApplication>
//#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QUrl>
#include <QtQml> //qmlRegisterUncreatableType
#include <mymodel.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MyModel myModel(0);

    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QQuickView view;
    view.setSource(QUrl("qrc:/main.qml"));

    qmlRegisterUncreatableType<MyModel>("GLENN.COM", 1, 0, "MyModel", "?");

    QStringList dataList;
       dataList.append("Item 1");
       dataList.append("Item 2");
       dataList.append("Item 3");
       dataList.append("Item 4");

    view.rootContext()->setContextProperty("myModel", QVariant::fromValue(dataList));
    view.rootContext()->setContextProperty("myModel", &myModel);

    view.show();

    return app.exec();
}
