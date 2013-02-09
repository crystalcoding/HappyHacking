#include "bball.h"
#include "ui_bball.h"

bball::bball(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bball)
{
    ui->setupUi(this);
}

bball::~bball()
{
    delete ui;
}
