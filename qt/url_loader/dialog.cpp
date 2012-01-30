#include "dialog.h"
#include "ui_dialog.h"

#include <QtWebKit>
#include <QTimer>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    totalRefresh=0;
    view = new QWebView();
    view->load(QUrl("http://www.google.com"));
    ui->verticalLayout->addWidget(view);

    this->setLayout(ui->verticalLayout);

    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(goUrl()));
    connect(ui->goPushButton, SIGNAL(clicked()), this, SLOT(goUrl()));

    timer->start(5000);
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::goUrl()
{
    QUrl qUrl = ui->urlLineEdit->text();
    view->load(qUrl);
    ui->lcdNumber->display(QString::number(++totalRefresh));
}
