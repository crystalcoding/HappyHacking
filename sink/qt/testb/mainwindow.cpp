#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLabel"
#include "QFontDatabase"
#include "QDebug"
#include "QTextCodec"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFontDatabase database;
    ui->setupUi(this);
    int count = 0;
    qDebug() << database.families().count();
    foreach (const QString &family, database.families()) {
    //for (int i=0;i<10;i++) {
    //for(int i=0;i<database.families().count(); i++) {
        //if (count>150) break;
        if (family == "cmsy10") continue;
        if (family == "cmex10") continue;
        if (family == "Dingbats") continue;
        //QLabel *label = new QLabel(ui->centralWidget);
        QLabel *label = new QLabel();
        QFont font;
        //QString str = QString("%1Glenn Chen").arg(count);
        //QString str = "Typography";
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
        QString str = "Srđan Prodanovic";
        qDebug() << str;
        //font.setFamily(family);

        //font.setPixelSize(20);
        //font.setBold(true);
        label->setFont(QFont(family,5));
        label->setText(str);
        //label->setToolTip(font.family());
        label->setForegroundRole(QPalette::Dark);
        label->setMinimumWidth(label->sizeHint().width());

        label->installEventFilter(this);

        //ui->horizontalLayout->addWidget(label);

//        row = count % 20;
//        if (count % 20 == 0) column++;
//        ui->gridLayout->addWidget(label, row, column);
//        ++count;
//        ++row;

        ++count;
        font_vector.append(label);
    }

    //setStyleSheet("background:transparent");
    //setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    populate_fonts();
}

bool MainWindow::eventFilter(QObject *watched, QEvent *e)
{

    QLabel *label = qobject_cast<QLabel*>(watched);
    if (label && e->type() == QEvent::Enter){
        label->setForegroundRole(QPalette::Light);
        label->setFont(QFont(label->font().family(),5));

        ui->label->setText(label->text());
        ui->label->setFont(QFont(label->font().family(),15));
        //ui->label->setAlignment(Qt::AlignCenter);
        ui->label->setForegroundRole(QPalette::Highlight);
        ui->label_2->setText(label->font().family());
        ui->label_2->setForegroundRole(QPalette::Dark);
        return false;
    }
    if (label && e->type() == QEvent::Leave) {
        label->setForegroundRole(QPalette::Dark);
        label->setFont(QFont(label->font().family(),5));
        return false;
    }
//    if (e->type() == QEvent::MouseButtonDblClick) {
//        qDebug() << "clear!";
//        for(int i=0; i< font_vector.count(); ++i) {
//            //font_vector.at(i)->clear();
//            qDebug() << font_vector.at(i)->text();
//            qDebug() <<  "total" << font_vector.count();
//            return true;
//        }
//    }
    qDebug() << e->type();
    return QWidget::eventFilter(watched, e);
}

void MainWindow::populate_fonts()
{
    int row = 0;
    int column = 0;
    for(int i=0; i< font_vector.count(); ++i) {
        if (i==70) break;
        row = i % 10;
        if (i % 10 == 0) column++;
        ui->gridLayout->addWidget(font_vector.at(i), row, column);
        ++row;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    for (int i=0; i<font_vector.count(); ++i) {
        //font_vector.at(i)->setText("");
        font_vector.at(i)->setText(arg1);
    }
}
