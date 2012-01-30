/********************************************************************************
** Form generated from reading ui file 'SimpleDialog.ui'
**
** Created: Thu May 28 19:37:44 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SIMPLEDIALOG_H
#define UI_SIMPLEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_SimpleDialog
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_increase;
    QSlider *horizontalSlider;
    QPushButton *pushButton_decrease;

    void setupUi(QDialog *SimpleDialog)
    {
    if (SimpleDialog->objectName().isEmpty())
        SimpleDialog->setObjectName(QString::fromUtf8("SimpleDialog"));
    SimpleDialog->resize(365, 186);
    buttonBox = new QDialogButtonBox(SimpleDialog);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setGeometry(QRect(0, 130, 341, 32));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    pushButton_increase = new QPushButton(SimpleDialog);
    pushButton_increase->setObjectName(QString::fromUtf8("pushButton_increase"));
    pushButton_increase->setGeometry(QRect(20, 10, 80, 26));
    horizontalSlider = new QSlider(SimpleDialog);
    horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
    horizontalSlider->setGeometry(QRect(30, 50, 160, 16));
    horizontalSlider->setOrientation(Qt::Horizontal);
    pushButton_decrease = new QPushButton(SimpleDialog);
    pushButton_decrease->setObjectName(QString::fromUtf8("pushButton_decrease"));
    pushButton_decrease->setGeometry(QRect(110, 10, 80, 26));

    retranslateUi(SimpleDialog);
    QObject::connect(buttonBox, SIGNAL(accepted()), SimpleDialog, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), SimpleDialog, SLOT(reject()));
    QObject::connect(pushButton_increase, SIGNAL(clicked()), horizontalSlider, SLOT(addStep()));
    QObject::connect(pushButton_decrease, SIGNAL(clicked()), horizontalSlider, SLOT(subtractStep()));

    QMetaObject::connectSlotsByName(SimpleDialog);
    } // setupUi

    void retranslateUi(QDialog *SimpleDialog)
    {
    SimpleDialog->setWindowTitle(QApplication::translate("SimpleDialog", "Dialog", 0, QApplication::UnicodeUTF8));
    pushButton_increase->setText(QApplication::translate("SimpleDialog", "Increase", 0, QApplication::UnicodeUTF8));
    pushButton_decrease->setText(QApplication::translate("SimpleDialog", "Decrease", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(SimpleDialog);
    } // retranslateUi

};

namespace Ui {
    class SimpleDialog: public Ui_SimpleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLEDIALOG_H
