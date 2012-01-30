#include "widget.h"
#include "ui_widget.h"

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDir>

#include <vector>
#include <cstdio>
#include <ctime>
#include <iostream>

Widget::Widget(QGraphicsView *parent)
    : QGraphicsView(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(shuffle()));
    //scene.addText("Hello World!");
    load_cards();
    this->setScene(&scene); //remember this widget derived from QGraphicsView

    shuffle();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::load_cards()
{
//    QGraphicsPixmapItem* qgp;
//    qgp = scene.addPixmap(QPixmap("./card_pics/clubs-2-75.png"));
//    qgp->setPos(0,0);
//    graphics_vector.push_back(qgp);
//    qgp = scene.addPixmap(QPixmap("./card_pics/clubs-3-75.png"));
//    qgp->setPos(100,0);
//    graphics_vector.push_back(qgp);
//    qgp = scene.addPixmap(QPixmap("./card_pics/clubs-4-75.png"));
//    qgp->setPos(200,0);
//    graphics_vector.push_back(qgp);

    QDir qdir;
    qdir.cd("card_pics"); //hard code for now
    QFileInfoList list = qdir.entryInfoList();
    QFileInfo info;
    QGraphicsPixmapItem* qgp;
    for (int i=0,row=0,column=0; i<list.length();++i){
        info = list.at(i);
        QString file_name = "./card_pics/"+info.fileName();

        qgp = scene.addPixmap(QPixmap(file_name));
        std::cout << info.fileName().toStdString() << std::endl;
        std::cout << "count:" << i << std::endl;


        if (i%10==0)
            ++row;
        column = i%11; //hold 10 cards per line
        qgp->setPos(column*70,row*100);

        graphics_vector.push_back(qgp);
    }

}

//Knuth's Shuffle
void Widget::shuffle()
{
    srand(time(NULL));
    int len = static_cast<int>(graphics_vector.size());
    for (int i = len-1; i>0; --i) {
        int rand_index = rand() % (i + 1);
        swap_card(i,rand_index);
    }
}

void Widget::swap_card(int index1, int index2)
{
    QPointF tempPoint = graphics_vector[index1]->pos();
    graphics_vector[index1]->setPos(graphics_vector[index2]->pos());
    graphics_vector[index2]->setPos(tempPoint);
}
