#include <QApplication>

#include "myqtapp.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  myQtApp *dialog = new myQtApp;
  
  dialog->setAttribute(Qt::WA_QuitOnClose);
  dialog->show();
  return app.exec();
}
