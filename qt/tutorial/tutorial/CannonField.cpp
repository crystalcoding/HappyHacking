#include "CannonField.h"
#include <QPainter>
#include <iostream>
#include <math.h>
#include <QTimer>

using namespace std;

CannonField::CannonField(QWidget *parent) : QWidget(parent)
{
    currentAngle = 45;
    currentForce = 0;
    autoShootTimer = new QTimer(this);
    connect(autoShootTimer, SIGNAL(timeout()),
            this, SLOT(moveShot()));
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true); 
    shootAngle = 0;
    shootForce = 0;
    newTarget();
}

void CannonField::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    paintCannon(painter);
    paintTarget(painter);
    if(autoShootTimer->isActive())
        paintShot(painter);
}

void CannonField::paintCannon(QPainter &painter)
{
    //painter.drawText(200,200, tr("Angle")+QString::number(currentAngle));
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::blue);

    painter.save();

    cout << rect().height() << endl;
    painter.translate(0,rect().height());
    painter.drawPie(QRect(-35, -35, 70, 70),0, 90*16);
                         //x(into), y(up),width, height
                         //0, 3'oclock
                         // 90 degree, counter-clockwise
    painter.rotate(-currentAngle);
    painter.drawRect(QRect(30,-5,20,10));

    painter.restore();

}

void CannonField::paintTarget(QPainter &painter)
{
    painter.setPen(Qt::black);
    painter.setBrush(Qt::red);
    painter.drawRect(targetRect());
}

void CannonField::paintShot(QPainter &painter)
{
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.drawRect(shotRect());
}
 const QRect barrelRect(30, -5, 20, 10);
QRect CannonField::shotRect() const
{
    const double gravity = 4;
    double time = timerCount /20.0;
    double velocity = shootForce;
    double radians = shootAngle *3.41159265/180;

    double velx = velocity *cos(radians);
    double vely = velocity *sin(radians);
    double x0 = (barrelRect.right()) +5 * cos(radians);
    double y0 = (barrelRect.right()) +5 * sin(radians);
    double x = x0+velx*time;
    double y = y0+vely*time -0.5*gravity*time*time;

    QRect result (0,0,6,6);
    result.moveCenter(QPoint(qRound(x), height() - 1 - qRound(y)));
    return result;
}

QRect CannonField::targetRect() const
{
    QRect result(0,0,20,10);
    result.moveCenter(QPoint(target.x(), height()-1-target.y()));
    return result;
}

void CannonField::setAngle(int angle)
{
//    switch (angle)
//    {
//        case angle<5:
//            angle = 5;
//            break;
//        case angle>70:
//            angle = 70;
//            break;
//        case currentAngle == angle:
//             break;
//    }
    if (angle <5) currentAngle = 5;
    if (angle >70) currentAngle = 70;
    if (currentAngle == angle) return;

    currentAngle = angle;
    update(CannonField::cannonRectangle());
    emit angleChanged(currentAngle);
}

void CannonField::setForce(int newForce)
{
    if (newForce <0) currentForce =0;
    if (newForce == currentForce) return;

    currentForce = newForce;
    emit forceChanged(currentForce);
}

QRect CannonField::cannonRectangle() const
{
    QRect result(0,0,50,50);
    result.setBottomLeft(rect().bottomLeft());
    return result;
}

void CannonField::shoot()
{
    if (autoShootTimer->isActive())
        return;
    timerCount = 0;
    shootAngle = currentAngle;
    shootForce = currentForce;
    autoShootTimer->start(5);
}

void CannonField::moveShot()
{
    QRegion region = shotRect();
    ++timerCount;

    QRect shotR = shotRect();

    if (shotR.intersects(targetRect())){
       autoShootTimer->stop();
       emit hit();
    }
    else if (shotR.x() > width() || shotR.y() > height()){
        autoShootTimer->stop();
        emit missed();
    } else {
        region = region.unite(shotR);
    }
    update(region);
}

void CannonField::newTarget()
{
    static bool firstTime = true;
    if (firstTime) {
        firstTime = false;
        //QTimer midnight(0,0,0);
        //qstrand((QTime::currentTime()));
    }
    target = QPoint(200+qrand()%190,10+qrand()%255);
    update();
}
