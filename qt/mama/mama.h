#ifndef MAMA_H
#define MAMA_H

#include <QtGui/QDialog>
#include <QtCore> //for QProcess
#include <QCloseEvent> //to prevent window from closing

namespace Ui
{
    class Mama;
}

class Mama : public QDialog
{
    Q_OBJECT

public:
    Mama(QWidget *parent = 0);
    ~Mama();
public slots:
    void launchBrowser();
    void launchNews();
    void launchEmail();
    void launchMovies();

protected:
        void closeEvent(QCloseEvent *e);

private:
    Ui::Mama *ui;

    QProcess qProcess;
    QString browserCmd, newsCmd, emailCmd, movieCmd;
    QStringList browserArg,newsArg,emailArg,movieArg;

    bool buildCommands();
    bool buildButtonImage();
};

#endif // MAMA_H
