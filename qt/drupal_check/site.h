#ifndef SITE_H
#define SITE_H

#include <QUrl>
#include <QString>

class Site
{
public:
    Site(); //QVector requires default constructor :)
    Site(QString url);
    ~Site();

    QUrl url;
    QString title;
    bool isDrupal;
    QString drupalVersion;

    QString getProtocol() const;

};

#endif // SITE_H
