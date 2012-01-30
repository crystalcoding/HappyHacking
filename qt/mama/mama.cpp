#include "mama.h"
#include "ui_mama.h"

#include <iostream>
using namespace std;

Mama::Mama(QWidget *parent)
    : QDialog(parent), ui(new Ui::Mama)
{
    ui->setupUi(this);
    setStyleSheet("background-color:blue");
    setStyleSheet("QPushButton:hover:!pressed { background: pink; }");
    buildCommands();
    buildButtonImage();

    this->setWindowOpacity(.5);

    QObject::connect(ui->internetPushButton, SIGNAL(clicked()), this, SLOT(launchBrowser()));
    QObject::connect(ui->newsPushButton, SIGNAL(clicked()), this, SLOT(launchNews()));
    QObject::connect(ui->emailPushButton, SIGNAL(clicked()), this, SLOT(launchEmail()));
    QObject::connect(ui->moviePushButton, SIGNAL(clicked()), this, SLOT(launchMovies()));
}

Mama::~Mama()
{
    delete ui;
}

void Mama::launchBrowser()
{
    qProcess.start(browserCmd, browserArg);
}

void Mama::launchNews()
{
    qProcess.start(newsCmd, newsArg);
}

void Mama::launchEmail()
{
    qProcess.start(emailCmd, emailArg);
}

void Mama::launchMovies()
{
    qProcess.start(movieCmd, movieArg);
}

bool Mama::buildCommands()
{
    QFile cmdFile("cmd.txt");
    //Use :/ prefix if cmd.txt is embedded into resource
    //QFile cmdFile(":/cmd.txt");

    if (!cmdFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        cerr << "File" << "cmd.txt" << "does not exit" << endl;
        return false;
    }

    while (!cmdFile.atEnd()){
        QByteArray line = cmdFile.readLine();
        if (line.simplified() == QByteArray("browser")){
            line = cmdFile.readLine();
            QList<QByteArray> qList = line.split(',');
            browserCmd = qList[0];
            browserArg = QStringList(qList[1]);
        }
        if (line.simplified() == QByteArray("news")){
            line = cmdFile.readLine();
            QList<QByteArray> qList = line.split(',');
            newsCmd = qList[0];
            newsArg = QStringList(qList[1]);
        }
        if (line.simplified() == QByteArray("email")){
            line = cmdFile.readLine();
            QList<QByteArray> qList = line.split(',');
            emailCmd = qList[0];
            emailArg = QStringList(qList[1]);
        }
        if (line.simplified() == QByteArray("movie")){
            line = cmdFile.readLine();
            QList<QByteArray> qList = line.split(',');
            movieCmd = qList[0];
            movieArg = QStringList(qList[1]);
        }
    }
    QString fileName = QDir::currentPath();
    QIcon icon4;
    fileName += "\\img\\chopper.jpg";
    icon4.addPixmap(QPixmap(fileName), QIcon::Normal, QIcon::Off);

    ui->toolButton->setIcon(icon4);
    ui->toolButton->setIconSize(QSize(90, 90));

    return true;
}

bool Mama::buildButtonImage()
{
    QString imagePath = QDir::currentPath();
    QIcon qIcon;

    qIcon.addPixmap(QPixmap(imagePath+"\\chopper.jpg"), QIcon::Normal, QIcon::Off);
    ui->toolButton->setIcon(qIcon);
    ui->toolButton_2->setIcon(qIcon);
    ui->toolButton_3->setIcon(qIcon);

    QIcon qIcon1;
    qIcon1.addPixmap(QPixmap(imagePath+"\\firefox.jpg"), QIcon::Normal, QIcon::Off);
    ui->internetPushButton->setIcon(qIcon1);

    QIcon qIcon2;
    qIcon2.addPixmap(QPixmap(imagePath+"\\kimo.jpg"), QIcon::Normal, QIcon::Off);
    ui->newsPushButton->setIcon(qIcon2);

    QIcon qIcon3;
    qIcon3.addPixmap(QPixmap(imagePath+"\\email.jpg"), QIcon::Normal, QIcon::Off);
    ui->emailPushButton->setIcon(qIcon3);

    QIcon qIcon4;
    qIcon4.addPixmap(QPixmap(imagePath+"\\movie.jpg"), QIcon::Normal, QIcon::Off);
    ui->moviePushButton->setIcon(qIcon4);

    return true;
}

void Mama::closeEvent(QCloseEvent *e)
{
    //e->ignore();
    //this->showMinimized();
    e->accept();
}
