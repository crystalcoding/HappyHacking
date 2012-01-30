/********************************************************************************
** Form generated from reading ui file 'mama.ui'
**
** Created: Thu Jun 25 00:41:54 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAMA_H
#define UI_MAMA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Mama
{
public:
    QPushButton *newsPushButton;
    QPushButton *internetPushButton;
    QPushButton *emailPushButton;
    QPushButton *moviePushButton;
    QLabel *newsLabel;
    QLabel *internetLabel;
    QLabel *emailLabel;
    QLabel *movieLabel;
    QFrame *line;
    QFrame *line_3;
    QFrame *line_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *line_4;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;

    void setupUi(QDialog *Mama)
    {
        if (Mama->objectName().isEmpty())
            Mama->setObjectName(QString::fromUtf8("Mama"));
        Mama->setWindowModality(Qt::NonModal);
        Mama->resize(332, 410);
        Mama->setAutoFillBackground(false);
        newsPushButton = new QPushButton(Mama);
        newsPushButton->setObjectName(QString::fromUtf8("newsPushButton"));
        newsPushButton->setGeometry(QRect(10, 160, 151, 81));
        QFont font;
        font.setPointSize(18);
        newsPushButton->setFont(font);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8("img/kimo.JPG")), QIcon::Normal, QIcon::Off);
        newsPushButton->setIcon(icon);
        newsPushButton->setIconSize(QSize(70, 70));
        internetPushButton = new QPushButton(Mama);
        internetPushButton->setObjectName(QString::fromUtf8("internetPushButton"));
        internetPushButton->setGeometry(QRect(10, 80, 151, 81));
        internetPushButton->setFont(font);
        QIcon icon1;
        icon1.addPixmap(QPixmap(QString::fromUtf8("img/firefox.jpg")), QIcon::Normal, QIcon::Off);
        internetPushButton->setIcon(icon1);
        internetPushButton->setIconSize(QSize(70, 70));
        emailPushButton = new QPushButton(Mama);
        emailPushButton->setObjectName(QString::fromUtf8("emailPushButton"));
        emailPushButton->setGeometry(QRect(10, 240, 151, 81));
        emailPushButton->setMinimumSize(QSize(131, 71));
        emailPushButton->setFont(font);
        QIcon icon2;
        icon2.addPixmap(QPixmap(QString::fromUtf8("img/email.jpg")), QIcon::Normal, QIcon::Off);
        emailPushButton->setIcon(icon2);
        emailPushButton->setIconSize(QSize(70, 70));
        moviePushButton = new QPushButton(Mama);
        moviePushButton->setObjectName(QString::fromUtf8("moviePushButton"));
        moviePushButton->setGeometry(QRect(10, 320, 151, 81));
        moviePushButton->setMinimumSize(QSize(131, 71));
        moviePushButton->setFont(font);
        QIcon icon3;
        icon3.addPixmap(QPixmap(QString::fromUtf8("img/movie.jpg")), QIcon::Normal, QIcon::Off);
        moviePushButton->setIcon(icon3);
        moviePushButton->setIconSize(QSize(70, 70));
        newsLabel = new QLabel(Mama);
        newsLabel->setObjectName(QString::fromUtf8("newsLabel"));
        newsLabel->setGeometry(QRect(170, 50, 161, 81));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        newsLabel->setFont(font1);
        internetLabel = new QLabel(Mama);
        internetLabel->setObjectName(QString::fromUtf8("internetLabel"));
        internetLabel->setGeometry(QRect(170, 130, 91, 71));
        internetLabel->setFont(font1);
        emailLabel = new QLabel(Mama);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));
        emailLabel->setGeometry(QRect(170, 180, 101, 141));
        emailLabel->setFont(font1);
        movieLabel = new QLabel(Mama);
        movieLabel->setObjectName(QString::fromUtf8("movieLabel"));
        movieLabel->setGeometry(QRect(170, 290, 201, 81));
        movieLabel->setFont(font1);
        line = new QFrame(Mama);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(170, 170, 141, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(Mama);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(170, 330, 141, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Mama);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(170, 80, 141, 41));
        QFont font2;
        font2.setItalic(true);
        line_2->setFont(font2);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(Mama);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 260, 121, 31));
        label_2 = new QLabel(Mama);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(170, 180, 151, 21));
        label_3 = new QLabel(Mama);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 110, 101, 20));
        label_4 = new QLabel(Mama);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 350, 101, 16));
        line_4 = new QFrame(Mama);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(170, 250, 141, 21));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        toolButton = new QToolButton(Mama);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(30, 0, 91, 71));
        QIcon icon4;
        icon4.addPixmap(QPixmap(QString::fromUtf8("img/chopper.jpg")), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon4);
        toolButton->setIconSize(QSize(90, 90));
        toolButton_2 = new QToolButton(Mama);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(120, 0, 91, 71));
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(90, 90));
        toolButton_3 = new QToolButton(Mama);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(210, 0, 91, 71));
        QIcon icon5;
        icon5.addPixmap(QPixmap(QString::fromUtf8("img/chopper.png")), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon5);
        toolButton_3->setIconSize(QSize(90, 90));

        retranslateUi(Mama);

        QMetaObject::connectSlotsByName(Mama);
    } // setupUi

    void retranslateUi(QDialog *Mama)
    {
        Mama->setWindowTitle(QApplication::translate("Mama", "Mama", 0, QApplication::UnicodeUTF8));
        Mama->setStyleSheet(QApplication::translate("Mama", "QPushButton:hover:!pressed { background-color: red; }", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        newsPushButton->setToolTip(QApplication::translate("Mama", "News", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        newsPushButton->setText(QApplication::translate("Mama", "News", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        internetPushButton->setToolTip(QApplication::translate("Mama", "Wath YouTube", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        internetPushButton->setStyleSheet(QString());
        internetPushButton->setText(QApplication::translate("Mama", "Web", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        emailPushButton->setToolTip(QApplication::translate("Mama", "Check Email", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        emailPushButton->setText(QApplication::translate("Mama", "Email", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        moviePushButton->setToolTip(QApplication::translate("Mama", "Video Show", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        moviePushButton->setText(QApplication::translate("Mama", "Movie", 0, QApplication::UnicodeUTF8));
        newsLabel->setText(QApplication::translate("Mama", "YouTube ", 0, QApplication::UnicodeUTF8));
        internetLabel->setText(QApplication::translate("Mama", "Read News", 0, QApplication::UnicodeUTF8));
        emailLabel->setText(QApplication::translate("Mama", "Write Email", 0, QApplication::UnicodeUTF8));
        movieLabel->setText(QApplication::translate("Mama", "Enjoy Movies", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Mama", "Check your email today?", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Mama", "What happen in the world?", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Mama", "Watch online video!", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Mama", "And Cartoon too !", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton->setToolTip(QApplication::translate("Mama", "HAHA", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton->setText(QApplication::translate("Mama", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_2->setToolTip(QApplication::translate("Mama", "HAHAHA!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_2->setText(QApplication::translate("Mama", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolButton_3->setToolTip(QApplication::translate("Mama", "HAHAHAHAHHAHAHAHA!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolButton_3->setText(QApplication::translate("Mama", "...", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Mama);
    } // retranslateUi

};

namespace Ui {
    class Mama: public Ui_Mama {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAMA_H
