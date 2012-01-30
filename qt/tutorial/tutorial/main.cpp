#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QSlider>
#include <QLCDNumber>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include "myWidget.h"
#include "CannonField.h"
#include "scoreboard.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  //QPushButton *quit = new QPushButton(("&Quit"));
  QPushButton *quit = new QPushButton(QObject::tr("Quit"));
  quit->setFont(QFont("Times", 18, QFont::Bold));
  QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));



  QGridLayout *gridLayout = new QGridLayout;
  gridLayout->addWidget(quit, 0,0);

//  myWidget *previousWidget;
//  for (int row=1; row<4; ++row){
//    for (int col=0; col<3; ++col){
//      myWidget *combine = new myWidget();
//      gridLayout.addWidget(combine);
//
//      if (!(row ==1 && col ==0)){
//	combine->linkPreviousWidget(previousWidget);
//      }
//      previousWidget = combine;
//    }
//  }

  myWidget *angle = new myWidget;
  gridLayout->addWidget(angle, 1, 0, 1, 1);

  myWidget *force = new myWidget;
  gridLayout->addWidget(force, 2,0,1,1);

  CannonField *cannonField = new CannonField;
  gridLayout->addWidget(cannonField, 1,1, 2, 3);

  gridLayout->setColumnStretch(1,20);

  //why we need this?
  QObject::connect(cannonField, SIGNAL(angleChanged(int)),
          angle, SLOT(setValue(int)));
  QObject::connect(cannonField, SIGNAL(forceChanged(int)),
                   force, SLOT(setValue(int)));

  QObject::connect(angle, SIGNAL(valueChanged(int)),
                   cannonField, SLOT(setAngle(int)));
  QObject::connect(force, SIGNAL(valueChanged(int)),
                   cannonField, SLOT(setForce(int)));
  angle->setValue(60);
  angle->setFocus();
  angle->setLabelText("Angle");

  force->setValue(15);
  force->setLabelText("Force");

  QPushButton *shoot = new QPushButton(QObject::tr("&Shoot"));
  shoot->setFont(QFont("Times", 18, QFont::Bold));
  QObject::connect(shoot, SIGNAL(clicked()), cannonField, SLOT(shoot()));

  gridLayout->addWidget(shoot, 3,0);

  ScoreBoard *scoreBoard = new ScoreBoard;
  QObject::connect(cannonField, SIGNAL(hit()), scoreBoard, SLOT(countHit()));
  QObject::connect(cannonField, SIGNAL(missed()), scoreBoard, SLOT(countMiss()));

  gridLayout->addWidget(scoreBoard, 0, 1, 1, 2);

  QWidget window;
  window.setLayout(gridLayout);
  window.setGeometry(100, 100, 500, 500);
  window.show();
  return app.exec();
}
