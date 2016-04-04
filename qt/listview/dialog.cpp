#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    for (int i=0;i<10;++i){
        ui->listWidget->addItem(QString::number(i));
    }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //ui->listWidget->currentItem()->setBackground();
    QListWidgetItem *item = ui->listWidget->currentItem();
    item->setBackgroundColor(Qt::black);
}
