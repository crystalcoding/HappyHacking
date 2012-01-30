#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QSlider>
#include <QLCDNumber>
#include <QVBoxLayout>

class myWidget : public QWidget
{
public:
  myWidget(QWidget *parent=0);
};

myWidget::myWidget(QWidget *parent):QWidget(parent)
{
  //setFixedSize(200,120);
  QPushButton *quit = new QPushButton(tr("Quit"), this);
  //quit->setGeometry(62,40,75,30);
  quit->setFont(QFont("Times", 18, QFont::Bold));

  QLCDNumber *lcd = new QLCDNumber();
  lcd->setSegmentStyle(QLCDNumber::Filled);
  QSlider *slider = new QSlider(Qt::Horizontal);
  //slider->setMaximum(100);
  //slider->setMinimum(0);
  slider->setRange(0,99);
  slider->setPageStep(1);
  slider->setTickInterval(1);
  slider->setTickPosition(QSlider::TicksBelow);
  QVBoxLayout *vLayout = new QVBoxLayout();
  vLayout->addWidget(quit);
  vLayout->addWidget(lcd);
  vLayout->addWidget(slider);
  setLayout(vLayout);

  //BUG!QObject::connect(quit, SIGNAL(clicked()), this, SLOT(quit()));
  QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
  QObject::connect(slider, SIGNAL(valueChanged(int)), 
		   lcd, SLOT(display(int)));
  QObject::connect(lcd, SIGNAL(overflow()), qApp, SLOT(quit()));
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  
  for(int i=0;i<5;++i){
    myWidget *window = new myWidget();
    window->show();
  }
  return app.exec();
}
