#include "QVBoxLayout"
#include "QSlider"
#include "QLCDNumber"
#include "QLabel"
#include "myWidget.h"

myWidget::myWidget(QWidget *parent):QWidget(parent)
{
  lcd = new QLCDNumber();
  lcd->setSegmentStyle(QLCDNumber::Filled);
  slider = new QSlider(Qt::Horizontal);
  //slider->setMaximum(100);
  //slider->setMinimum(0);
  slider->setRange(0,99);
  slider->setPageStep(1);
  slider->setTickInterval(1);
  slider->setTickPosition(QSlider::TicksBelow);

  label = new QLabel;
  
  QVBoxLayout *vLayout = new QVBoxLayout();
  vLayout->addWidget(lcd);
  vLayout->addWidget(slider);
  vLayout->addWidget(label);
  setLayout(vLayout);

  //BUG!QObject::connect(quit, SIGNAL(clicked()), this, SLOT(quit()));
  QObject::connect(slider, SIGNAL(valueChanged(int)), 
		   lcd, SLOT(display(int)));

  QObject::connect(slider, SIGNAL(valueChanged(int)),
                   this, SIGNAL(valueChanged(int)));

  //slider->setValue(qrand()%100);
  slider->setRange(5,70);

  setFocusProxy(slider);

  //tutorial 7
}

void myWidget::linkPreviousWidget(myWidget* preWidget)
{
  QObject::connect(slider, SIGNAL(valueChanged(int)),
		   preWidget->slider, SLOT(setValue(int)));
}

void myWidget::setValue(int value)
{
    slider->setValue(value);
}

void myWidget::setLabelText(QString newText)
{
    label->setText(newText);
}
