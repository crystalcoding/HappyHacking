#include <QApplication>
#include "slider.h"
//#include <QtGui>


int main(int argc, char *argv[])
{
  QApplication ap(argc, argv);
  
  //slider s = slider; //wrong
  slider s;
  s.show();
  ap.exec();
}
