#include "bcdgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BCDGUI w;
    w.show();
    
    return a.exec();
}
