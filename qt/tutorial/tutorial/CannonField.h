#ifndef CANNONFIELD_H
#define CANNONFIELD_H
#include <QWidget>

class QTimer;
//class QPoint;

class CannonField : public QWidget
{
  //Q_Object; wrong
  Q_OBJECT

public:
  CannonField(QWidget *parent=0);
  int angle() const { return currentAngle;}
  int force() const { return currentForce;}
  ~CannonField() {}

public slots:
  void setAngle(int newAngle);
  void setForce(int newForce);
  void shoot();
  void newTarget();

private slots:
  void moveShot();

signals:
  void angleChanged(int angle);
  void forceChanged(int force);
  void hit();
  void missed();

protected:
  void paintEvent(QPaintEvent *event);

private:
  void paintShot(QPainter &painter);
  void paintCannon(QPainter &painter);
  void paintTarget(QPainter &painter);

  int currentAngle;
  int currentForce;
  QRect cannonRectangle() const;
  QRect shotRect() const;
  QRect targetRect() const;
  QPoint target;
  int timerCount;
  QTimer *autoShootTimer;
  float shootAngle;
  float shootForce;
};

#endif
