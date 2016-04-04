#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCustomPlot *customPlot = ui->qcustomplot;
    QVector<double> x(15), y(15); // completedAppointments = y

    x[0] = 0;
    for (int i=1; i<15; ++i)
    {
      x[i] = i;
    }

    y = {0, 25,116,93,74,90,96,118,156,151,146,165,144,138,126};
    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    customPlot->xAxis->setLabel("Week Number");
    customPlot->yAxis->setLabel("Completed Appointments");
    // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(0, 15);
    customPlot->yAxis->setRange(0, 200);
    customPlot->replot();

}

MainWindow::~MainWindow()
{
    delete ui;
}
