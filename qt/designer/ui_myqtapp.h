/********************************************************************************
** Form generated from reading ui file 'myqtapp.ui'
**
** Created: Thu May 28 18:18:44 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MYQTAPP_H
#define UI_MYQTAPP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_myQtAppDLG
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QSpinBox *spinBox1;
    QSpinBox *spinBox2;
    QPushButton *pushButton_browse;
    QPushButton *pushButton_do;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_about;
    QComboBox *comboBox;
    QCheckBox *checkBox;

    void setupUi(QDialog *myQtAppDLG)
    {
    if (myQtAppDLG->objectName().isEmpty())
        myQtAppDLG->setObjectName(QString::fromUtf8("myQtAppDLG"));
    myQtAppDLG->resize(400, 300);
    label = new QLabel(myQtAppDLG);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(40, 20, 54, 16));
    label_2 = new QLabel(myQtAppDLG);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(60, 80, 54, 16));
    label_3 = new QLabel(myQtAppDLG);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(60, 120, 54, 16));
    lineEdit = new QLineEdit(myQtAppDLG);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(110, 20, 151, 26));
    textEdit = new QTextEdit(myQtAppDLG);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));
    textEdit->setGeometry(QRect(60, 160, 311, 81));
    spinBox1 = new QSpinBox(myQtAppDLG);
    spinBox1->setObjectName(QString::fromUtf8("spinBox1"));
    spinBox1->setGeometry(QRect(130, 70, 51, 26));
    spinBox2 = new QSpinBox(myQtAppDLG);
    spinBox2->setObjectName(QString::fromUtf8("spinBox2"));
    spinBox2->setGeometry(QRect(130, 110, 51, 26));
    pushButton_browse = new QPushButton(myQtAppDLG);
    pushButton_browse->setObjectName(QString::fromUtf8("pushButton_browse"));
    pushButton_browse->setGeometry(QRect(270, 20, 80, 26));
    pushButton_do = new QPushButton(myQtAppDLG);
    pushButton_do->setObjectName(QString::fromUtf8("pushButton_do"));
    pushButton_do->setGeometry(QRect(60, 260, 91, 26));
    pushButton_clear = new QPushButton(myQtAppDLG);
    pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
    pushButton_clear->setGeometry(QRect(170, 260, 80, 26));
    pushButton_about = new QPushButton(myQtAppDLG);
    pushButton_about->setObjectName(QString::fromUtf8("pushButton_about"));
    pushButton_about->setGeometry(QRect(290, 260, 80, 26));
    comboBox = new QComboBox(myQtAppDLG);
    comboBox->setObjectName(QString::fromUtf8("comboBox"));
    comboBox->setGeometry(QRect(210, 110, 151, 26));
    checkBox = new QCheckBox(myQtAppDLG);
    checkBox->setObjectName(QString::fromUtf8("checkBox"));
    checkBox->setGeometry(QRect(240, 70, 81, 22));

    retranslateUi(myQtAppDLG);
    QObject::connect(pushButton_about, SIGNAL(clicked()), textEdit, SLOT(clear()));

    QMetaObject::connectSlotsByName(myQtAppDLG);
    } // setupUi

    void retranslateUi(QDialog *myQtAppDLG)
    {
    myQtAppDLG->setWindowTitle(QApplication::translate("myQtAppDLG", "My Designer Dialog", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("myQtAppDLG", "File", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("myQtAppDLG", "Number 1", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("myQtAppDLG", "Number 2", 0, QApplication::UnicodeUTF8));
    pushButton_browse->setText(QApplication::translate("myQtAppDLG", "Browse..", 0, QApplication::UnicodeUTF8));
    pushButton_do->setText(QApplication::translate("myQtAppDLG", "Do Something", 0, QApplication::UnicodeUTF8));
    pushButton_clear->setText(QApplication::translate("myQtAppDLG", "Clear", 0, QApplication::UnicodeUTF8));
    pushButton_about->setText(QApplication::translate("myQtAppDLG", "About", 0, QApplication::UnicodeUTF8));
    checkBox->setText(QApplication::translate("myQtAppDLG", "Yes or No", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(myQtAppDLG);
    } // retranslateUi

};

namespace Ui {
    class myQtAppDLG: public Ui_myQtAppDLG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYQTAPP_H
