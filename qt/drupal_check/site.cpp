#include "site.h"


Site::Site(): url(""), title(""), isDrupal(false), drupalVersion("n/a")
{

}

Site::Site(QString url): title(""), isDrupal(false), drupalVersion("n/a")
{
    this->url = url;
}

Site::~Site()
{

}

QString Site::getProtocol() const
{
    if (this->url.toString().contains("https")) {
        return "https://";
    } else {
        return "http://";
    }
}

