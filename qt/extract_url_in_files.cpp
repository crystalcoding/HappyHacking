/*/////
Qt Application that read all files in the current directory
find line which contain http
to deliver in windows, need some dlls
libgcc_s_dw2-1.dll
mingwm10.dll
QtCored4.dll
*//////

#include <QtCore/QCoreApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
using namespace std;

void find_url(QString filename)
{
    qDebug() << "opening file" << filename;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "cannot open file" << filename;
    QTextStream in(&file);
    while (!in.atEnd()){
        QString line = in.readLine();
        //qPrintable(QString("%1").arg(line));
        if (line.indexOf("http://") != -1){
            qDebug() << "found: " << line;
        }
    }
}

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    QDir dir("./");
    dir.setFilter(QDir::Files);
    QFileInfoList list = dir.entryInfoList();
    for (int i = 0; i < list.size(); ++i){
        QFileInfo fileInfo = list.at(i);
        //cout << qPrintable(QString("%1").arg(fileInfo.fileName()));
        //cout << endl;

        find_url(fileInfo.fileName());
        //find_url("/home/bpslinux/Downloads/url/url-build-desktop/in.txt");
    }
    //return a.exec();
    return 0;
}



