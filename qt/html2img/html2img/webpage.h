#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QImage>
#include <QPainter>
#include <QWebPage>
#include <QWebFrame>
#include <QUrl>

class webpage : public QObject // as parent if we want signal/slot,
                               //regen the Makefile to avoid the vtable not found error
{
    Q_OBJECT //do not forget this micro
public:
    webpage(const QUrl &l);

public slots:
   void readyToDraw();

private:
    QWebPage page;
    QUrl url;
    QImage *image;
    QPainter *painter;
};

#endif // WEBPAGE_H
