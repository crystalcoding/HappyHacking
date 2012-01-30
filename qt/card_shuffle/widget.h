#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>

#include <vector>
namespace Ui
{
    class Widget;
}

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    Widget(QGraphicsView *parent = 0);
    ~Widget();


private:
    Ui::Widget *ui;
    QGraphicsScene scene;

    std::vector<QGraphicsPixmapItem*> graphics_vector;
    QList<QGraphicsPixmapItem*> all_items;

    void load_cards();
    void swap_card(int,int);

private slots:
    void shuffle(); //position change

};

#endif // WIDGET_H
