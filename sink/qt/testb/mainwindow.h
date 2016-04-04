#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    bool eventFilter(QObject *watched, QEvent *e);
    ~MainWindow();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QVector<QLabel*> font_vector;
    void populate_fonts();
};

#endif // MAINWINDOW_H
