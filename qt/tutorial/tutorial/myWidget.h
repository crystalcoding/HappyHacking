#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>
class QLCDNumber;
class QSlider;
class QLabel;

class myWidget : public QWidget
{
  
Q_OBJECT

public:
  myWidget(QWidget *parent=0);
  void setLabelText(QString newText);
  void linkPreviousWidget(myWidget*);

  QLCDNumber *lcd;
  QSlider *slider;
  QLabel *label;

public slots:
  void setValue(int value);

signals:
  void valueChanged(int value);
};

#endif
