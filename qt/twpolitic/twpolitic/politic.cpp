#include "politic.h"
#include "ui_politic.h"
#include <QClipboard>
#include "stdlib.h"
#include <iostream>
#include <fstream>



politic::politic(QWidget *parent)
    : QDialog(parent), ui(new Ui::politic)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(play_video_script()));

    //QApplication::clipboard() return the single instance
    //dataChanged is already in the scope of clipboard?! cool
    connect(QApplication::clipboard(), SIGNAL(dataChanged()),
            this, SLOT(onDataChanged()));

    std::ifstream file(std::string("config").c_str());
    if (!file){
        std::cout << "Cannot open \"config\" file, need to run the command in there." << std::endl;
        //throw exception or abort the program?
    }

    file >> program;
    std::cout << program << std::endl;
    if (program.empty()){
        std::cout << "config file is empty, no program to run" << std::endl;
    }

}

politic::~politic()
{
    delete ui;
}

void politic::play_video_script()
{
    QClipboard *cb = QApplication::clipboard();
    QString url = cb->text();

//    QString script = QString(program.c_str());
//    script += " "+ url;
    std::string final_script;
    final_script += program + " " + url.toStdString();
    system(final_script.c_str());

    //debug
    //ui->lineEdit->setText(url);
}

void politic::onDataChanged()
{
    QClipboard *cb = QApplication::clipboard();
    std::string data = cb->text().toStdString();
    const std::string youtube = "http://www.youtube.com";
    if ( data.find(youtube) != std::string::npos){
        play_video_script();
    }
}
