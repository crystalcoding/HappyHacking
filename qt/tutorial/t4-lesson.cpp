#include <QApplication>
#include <QPushButton>
#include <QFont>

class myWidget : public QWidget
{
public:
  myWidget(QWidget *parent=0);
};

myWidget::myWidget(QWidget *parent):QWidget(parent)
{
  setFixedSize(200,120);
  QPushButton *quit = new QPushButton(tr("Quit"), this);
  quit->setGeometry(62,40,75,30);
  quit->setFont(QFont("Times", 18, QFont::Bold));
  //BUG!QObject::connect(quit, SIGNAL(clicked()), this, SLOT(quit()));
  QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
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
