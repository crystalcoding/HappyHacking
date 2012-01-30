/********************************************************************************
** Form generated from reading UI file 'politic.ui'
**
** Created: Sat Jun 12 01:00:00 2010
**      by: Qt User Interface Compiler version 4.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLITIC_H
#define UI_POLITIC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_politic
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *politic)
    {
        if (politic->objectName().isEmpty())
            politic->setObjectName(QString::fromUtf8("politic"));
        politic->resize(220, 63);
        pushButton = new QPushButton(politic);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 181, 41));

        retranslateUi(politic);

        QMetaObject::connectSlotsByName(politic);
    } // setupUi

    void retranslateUi(QDialog *politic)
    {
        politic->setWindowTitle(QApplication::translate("politic", "politic", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("politic", "Play Clipboard Url", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class politic: public Ui_politic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLITIC_H
