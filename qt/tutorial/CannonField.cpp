#include "CannonField.h"

CannonField::CannonField(QWidget *parent) : QWidget(parent)
{
currentAngle = 45;
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
 
}

//void CannonField::angleChanged(int angle)
//{
//}

void CannonField::paintEvent(QPaintEvent *e)
{
}

void CannonField::setAngle(int angle)
{
}
