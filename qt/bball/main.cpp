#include "bball.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bball w;
    w.show();
    
    return a.exec();
}
