#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFtp>
#include <QFile>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    QFtp *ftp;
    QFile *file;
private slots:
    void install();
    void ftpCommandFinished(int, bool);
    void updateDataTransferProgress(qint64 readBytes,
                                    qint64 totalBytes);
    void terminate_app();
};

#endif // DIALOG_H
