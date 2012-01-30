#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>

namespace Ui
{
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void addItem();
    void removeItem();
    void printPDF();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H