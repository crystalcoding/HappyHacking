#include "mama.h"
#include "ui_mama.h"

#include <QMessageBox>

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
//    QLabel *ext = new QLabel("Extension", this);
//    this->setExtension(ext);


    QObject::connect(ui->internetPushButton, SIGNAL(clicked()), this, SLOT(launchBrowser()));
    QObject::connect(ui->newsPushButton, SIGNAL(clicked()), this, SLOT(launchNews()));
    QObject::connect(ui->emailPushButton, SIGNAL(clicked()), this, SLOT(launchEmail()));
    QObject::connect(ui->moviePushButton, SIGNAL(clicked()), this, SLOT(launchMovies()));

    QObject::connect(ui->toolButton, SIGNAL(clicked(bool)), this, SLOT(showExtension(bool)));

    QObject::connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(funTollButton()));
}

Mama::~Mama()
{
    delete ui;
}

void Mama::launchBrowser()
{
    browserProcess.kill();
    browserProcess.start(browserCmd, browserArg);
}

void Mama::launchNews()
{
    newsProcess.kill();
    newsProcess.start(newsCmd, newsArg);
}

void Mama::launchEmail()
{
    emailProcess.kill();
    emailProcess.start(emailCmd, emailArg);
}

void Mama::launchMovies()
{
    movieProcess.kill();
    movieProcess.start(movieCmd, movieArg);
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

    QIcon qIcon;

    QString imagePath = "C:\\mama\\release\\img\\chopper.png";
    qIcon.addPixmap(QPixmap(imagePath), QIcon::Normal, QIcon::Off);
    ui->toolButton->setIcon(qIcon);
    ui->toolButton_2->setIcon(qIcon);
    ui->toolButton_3->setIcon(qIcon);

    QIcon qIcon1;
    imagePath = "C:\\mama\\release\\img\\firefox.jpg";
    qIcon1.addPixmap(QPixmap(imagePath), QIcon::Normal, QIcon::Off);
    ui->internetPushButton->setIcon(qIcon1);

    QIcon qIcon2;
    imagePath = "C:\\mama\\release\\img\\kimo.jpg";
    qIcon2.addPixmap(QPixmap(imagePath), QIcon::Normal, QIcon::Off);
    ui->newsPushButton->setIcon(qIcon2);

    QIcon qIcon3;
    imagePath = "C:\\mama\\release\\img\\email.jpg";
    qIcon3.addPixmap(QPixmap(imagePath), QIcon::Normal, QIcon::Off);
    ui->emailPushButton->setIcon(qIcon3);

    QIcon qIcon4;
    imagePath = "C:\\mama\\release\\img\\movie.jpg";
    qIcon4.addPixmap(QPixmap(imagePath), QIcon::Normal, QIcon::Off);
    ui->moviePushButton->setIcon(qIcon4);
    ui->moviePushButton->show();

    return true;
}

void Mama::funTollButton()
{
//    QMessageBox msgBox;
//    msgBox.setInformativeText("test tset");
//    msgBox.exec();


}

void Mama::closeEvent(QCloseEvent *e)
{
    //e->ignore();
    //this->showMinimized();
    e->accept();
}
