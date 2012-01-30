#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui/QDialog>

class QWebView;
class QTimer;

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
    int totalRefresh;

public slots:
    void goUrl();

private:
    Ui::Dialog *ui;

    QWebView *view;
    QTimer *timer;


};

#endif // DIALOG_H
