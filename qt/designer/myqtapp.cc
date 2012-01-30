#include <QtGui> 
#include "myqtapp.h"
 
// if we include <QtGui> there is no need to include every class used: <QString>, <QFileDialog>,...
 
myQtApp::myQtApp(QWidget *parent) : QDialog(parent)
{
  //Ui_myQtAppDLG ui;
  ui.setupUi(this); // this sets up GUI
 
    // signals/slots mechanism in action
    connect( ui.pushButton_browse, SIGNAL( clicked() ), this, SLOT( getPath() ) ); 
    connect( ui.pushButton_do, SIGNAL( clicked() ), this, SLOT( doSomething() ) ); 
    connect( ui.pushButton_clear, SIGNAL( clicked() ), this, SLOT( clear() ) ); 
    connect( ui.pushButton_about, SIGNAL( clicked() ), this, SLOT( about() ) ); 
}
 
 
void myQtApp::getPath()
{
    QString path;
    
    path = QFileDialog::getOpenFileName(
        this,
        "Choose a file to open",
        QString::null,
        QString::null);
 
    ui.lineEdit->setText( path );
}
 
 
void myQtApp::doSomething()
{
    int value1, value2;
    Qt::CheckState state;
    QString str;
 
    ui.textEdit->append( "Path to file: " + ui.lineEdit->text() );
 
    value1 = ui.spinBox1->value();
    value2 = ui.spinBox2->value();
 
    ui.textEdit->append( "Number 1 value: " + QString::number(value1) );
    ui.textEdit->append( "Number 2 value: " + QString::number(value2) );
 
    state = ui.checkBox->checkState();
 
    str = "Checkbox says: ";
    if ( state == Qt::Checked ) str += "yes"; 
    else str += "no";
    ui.textEdit->append( str );
 
    ui.textEdit->append( "ComboBox current text: " + ui.comboBox->currentText() );
    ui.textEdit->append( "ComboBox current item: " + QString::number(ui.comboBox->currentIndex()) );
}
 
 
void myQtApp::clear()
{
    ui.textEdit->clear();
}
 
 
void myQtApp::about() 
{
    QMessageBox::about(this,"About myQtApp",
                "This app was coded for educational purposes.\n"
                "Number 1 is: " + QString::number(ui.spinBox1->value()) + "\n\n"
                "Bye.\n");
}
