#include "webpage.h"
#include "QtGlobal"
#include <iostream>
using namespace std;
webpage::webpage(const QUrl &l): url(l)
{
    page.mainFrame()->load(url);
    QObject::connect(&page, SIGNAL(loadFinished(bool)),
            this, SLOT(readyToDraw()));
}

void webpage::readyToDraw()
{
    page.setViewportSize(page.mainFrame()->contentsSize());
    //cout << page.mainFrame()->toHtml().toStdString();
    QImage *image = new QImage(page.viewportSize(), QImage::Format_ARGB32);
    QPainter *painter = new QPainter();

    painter->begin(image);
    qDebug("s");
    page.mainFrame()->render(painter);
    painter->end();

    image->save("html2png.png");

    delete image;
    delete painter;
}
