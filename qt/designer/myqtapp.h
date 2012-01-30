#ifndef MYQTAPP_H
#define MYQTAPP_H

#include "ui_myqtapp.h" //prefix "ui_" 

class myQtApp : public QDialog//, private Ui::myQtAppDLG //name in designer
{
  Q_OBJECT

  public:
  myQtApp(QWidget *parent=0);

  public slots:
  void getPath();
  void doSomething();
  void clear();
  void about();
  
 private:
  Ui::myQtAppDLG ui;
};

#endif
