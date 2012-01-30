#include "widget.h"
#include "ui_widget.h"

#include <QPrinter>
#include <QPainter>
#include <QTextItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->addPushButton, SIGNAL(clicked()), this, SLOT(addItem()));
    connect(ui->removePushButton, SIGNAL(clicked()), this, SLOT(removeItem()));
    connect(ui->printPushButton, SIGNAL(clicked()), this, SLOT(printPDF()));

    this->setLayout(ui->gridLayout);

    this->setWindowTitle("ListWidget");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addItem()
{
    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void Widget::removeItem()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void Widget::printPDF()
{
    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("out.pdf");
    printer.newPage();

    QPainter painter(&printer);
    ui->listWidget->selectAll();
    QString output;
    QTextItem textItem;
    for(int row=0;row< ui->listWidget->count();++row)
    {
        output = ui->listWidget->item(row)->text();
        painter.drawText(0,row*15,output);
    }
    painter.end();
}
