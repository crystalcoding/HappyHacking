#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QDebug>
#include <QVector>
#include <QStringList>
#include <QRegExp>
#include <QUrl>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QClipboard>
#include <QKeyEvent>
#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <site.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool event(QEvent *event); //overwrite QObject::event? or QWidget?
    bool eventFilter(QObject *watched, QEvent *event);

    QTableWidget tableWidget;
    QVector<Site> sites;
    QClipboard *clipboard;
    int complete;

    int getSiteIndexByURL(QUrl url);
    void reportYesNo();
    void reportVersion();




private slots:
    void on_pushButton_clicked();
    void replyFinished(QNetworkReply*);
    void copyToClipboard();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
