#ifndef SIMPLESLIDE_H
#define SIMPLESLIDE_H

#include "ui_SimpleDialog.h" // ui_NAMEofYourWidgetFromDesigner
                             // must be included before running qmake?

class slider : public QDialog, private Ui_SimpleDialog 
                             //NOTE or"Ui::SimpleDialog"
{
  Q_OBJECT

  public:
  slider(QWidget *parent = 0);
};

#endif

