#ifndef POLITIC_H
#define POLITIC_H

#include <QtGui/QDialog>
#include <string>

namespace Ui
{
    class politic;
}

class politic : public QDialog
{
    Q_OBJECT

public:
    politic(QWidget *parent = 0);
    ~politic();

private slots:
    void play_video_script();
    void onDataChanged();

private:
    Ui::politic *ui;

    std::string program;
    std::string url;

};

#endif // POLITIC_H
