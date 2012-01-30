#include "dialog.h"
#include "ui_dialog.h"

#include <QClipboard>
#include <QTextCodec>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(processText()));
    connect(ui->copyAgainPushButton, SIGNAL(clicked()),
            this, SLOT(copyAgain()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::processText()
{
    //QString input = ui->inputBrowser->toPlainText();
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Big5"));

    QClipboard *clipboard = QApplication::clipboard();
    QString input = clipboard->text();
    ui->inputBrowser->setPlainText(input);
    QString output = "";
    foreach(QChar c, input)
    {
        if ( c != '*') output += c;
    }
    ui->outputBrowser->setPlainText(output);

    clipboard->setText(output);
}

void Dialog::copyAgain()
{
    ui->outputBrowser->selectAll();
    ui->outputBrowser->copy();
}
