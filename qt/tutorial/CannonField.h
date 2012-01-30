#ifndef CANNONFIELD_H
#define CANNONFIELD_H

#include <QWidget>
//#include <QObject>
class CannonField : public QWidget
{

  //Q_Object; wrong
  Q_OBJECT

public:
  CannonField(QWidget *parent=0);
 
  int angle() { return currentAngle;}
  ~CannonField() {}
public slots:
  void setAngle(int newAngle);

signals:
  void angleChanged(int angle);

protected:
  void paintEvent(QPaintEvent *event);


private:
  int currentAngle;
};

#endif
