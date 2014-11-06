#ifndef BBALL_H
#define BBALL_H

#include <QMainWindow>

namespace Ui {
class bball;
}

class bball : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit bball(QWidget *parent = 0);
    ~bball();
    
private:
    Ui::bball *ui;
};

#endif // BBALL_H
