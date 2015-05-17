#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "site.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->centralWidget->setWindowTitle("Are those sites Drupal?");

    ui->progressBar->setValue(0);
    this->complete = 0;

    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(3);
    QStringList header;
    header << "WEBSITE URL" << "DRUPAL?" << "Powered By";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    //ui->tableWidget->installEventFilter(this);

    ui->textEdit_2->hide();
    ui->textEdit_3->hide();

    clipboard = QApplication::clipboard();

    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged,
            this, &MainWindow::copyToClipboard);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent *event)
{
//    //if (!event) return false;

//    //qDebug() << event->type();
//    if (event->type() == QEvent::KeyPress){
//        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
//        //qDebug() << ke->key();
//    }

    return QWidget::event(event);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
//    if (watched == ui->tableWidget && event->type() == QEvent::KeyPress){
//        QKeyEvent *ke = static_cast<QKeyEvent *>(event);
//        if (ke->key() == Qt::Key_Control){
//            qDebug() << ke->key();
//            event->ignore();
//            return false;
//        }
//    }
    return QWidget::eventFilter(watched, event);
}

int MainWindow::getSiteIndexByURL(QUrl url)
{
    int index = 0;
    foreach(Site site, this->sites){
        if (site.url.host() == url.host()) {
            return index;
        }
        ++index;
    }
    return -1;
}

void MainWindow::reportYesNo()
{
    int index = 0;
    ui->textEdit_2->clear();
    foreach (Site site, this->sites) {
        if (site.isDrupal) {
            ui->textEdit_2->append(QString::number(index) + " " + "yes");
        } else {
            ui->textEdit_2->append(QString::number(index) + " " + "no");
        }
        ++index;
        //ui->textEdit_2->append("ok2");
    }

    for (int row=0; row<this->sites.count(); ++row) {
        QTableWidgetItem *item = ui->tableWidget->item(row, 1);
        if (this->sites[row].isDrupal) {
            item->setText("Yes");
            item->setBackground(QBrush(Qt::blue));
            item->setTextColor(Qt::green);
        } else {
            item->setText("No");
            item->setBackground(QBrush(Qt::darkRed));
            item->setTextColor(Qt::red);
        }
    }
    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::reportVersion()
{
    int index = 0;
    ui->textEdit_3->clear();
    foreach (Site site, this->sites) {
        if (site.drupalVersion=="") {
            qDebug() << "empty version?";
        }
        ui->textEdit_3->append(QString::number(index) + " " + site.drupalVersion);
        ++index;
    }


    for (int row=0; row<this->sites.count(); ++row) {
        QTableWidgetItem *item = ui->tableWidget->item(row, 2);
        item->setText(this->sites[row].drupalVersion);
    }
    ui->tableWidget->resizeColumnsToContents();
}

void MainWindow::on_pushButton_clicked()
{
    QString input = ui->textEdit->toPlainText();

    if (input.isEmpty()) {
        QMessageBox msg("Pleaes enter some links", "e.g. http://google.com",
                        QMessageBox::Warning, QMessageBox::Yes|QMessageBox::Default,
                        QMessageBox::No|QMessageBox::Escape, QMessageBox::NoButton);

        msg.exec();
        return;
    }

    //progress reset
    this->complete = 0;
    ui->progressBar->setValue(0);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));


    ui->textEdit_2->setText(ui->textEdit->toPlainText());

    QString urls = ui->textEdit_2->toPlainText();
    QStringList sList = urls.split(QRegExp("(\\r\\n)|(\\n\\r)|\\r|\\n"), QString::SkipEmptyParts);
    Site site(ui->textEdit_2->toPlainText());

    this->sites = QVector<Site>();
    foreach (const QString& aSiteUrl, sList) {
        //this->sites.append(site);
        QUrl testUrl = QUrl(aSiteUrl);
        if (!testUrl.isValid() || testUrl.host().isEmpty()) {
            qDebug() << "invalid Url found";
            //QDialog *popUp = new QDialog(this);
            QMessageBox msg("Invalid URL", "Pleaes check any invalid URL",
                            QMessageBox::Warning, QMessageBox::Yes|QMessageBox::Default,
                            QMessageBox::No|QMessageBox::Escape, QMessageBox::NoButton);

            msg.exec();

            return;
        }
        Site m_site(aSiteUrl);
        this->sites.append(m_site);
    }

    ui->tableWidget->clear();
    QStringList header;
    header << "WEBSITE URL" << "DRUPAL?" << "Powered By";
    ui->tableWidget->setHorizontalHeaderLabels(header);
    //ui->tableWidget->setRowCount(10);
    //ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(this->sites.count());
    for (int row=0; row<this->sites.count(); ++row) {
        for (int col=0; col<3; ++col) {
            if (col==0) {
                QTableWidgetItem *item = new QTableWidgetItem(this->sites[row].url.toString());
                ui->tableWidget->setItem(row, col, item);
            } else {
                QTableWidgetItem *item = new QTableWidgetItem("");
                ui->tableWidget->setItem(row, col, item);
            }
        }
    }
    ui->tableWidget->resizeColumnsToContents();



    //QTableWidgetItem *item = new QTableWidgetItem("hello");
    //ui->tableWidget->setItem(1,1, item);


    ui->textEdit->clear();
    int index = 0;
    foreach (const Site& site, this->sites) {
        //ui->textEdit->append(QString::number(index) + " " + site.url.toString());
        ui->textEdit->append(site.url.toString());
        ++index;
    }

    QString host = "";
    QString drupalJS = "";
    QString drupalChangelog = "";

    foreach (const Site& aSite, this->sites) {
        host = aSite.getProtocol() + aSite.url.host();
        drupalJS = host + "/misc/drupal.js";
        drupalChangelog = host + "/CHANGELOG.txt";
        manager->get(QNetworkRequest(QUrl(drupalChangelog)));
        manager->get(QNetworkRequest(QUrl(drupalJS)));
    }



//    QString host = "http://www.aaoinfo.org/";
//    QString drupalJS = host + "misc/drupal.js";
//    QString drupalChangelog = host + "CHANGELOG.txt";
//    //check = "http://google.com";
//    //manager->get(QNetworkRequest(QUrl("http://secondform.com/")));
//    //manager->get(QNetworkRequest(QUrl("http://www.secondform.com/misc/drupal.js")));
//    //manager->get(QNetworkRequest(QUrl("https://www.aaoinfo.org/misc/drupal.js")));
//    //manager->get(QNetworkRequest(QUrl("http://equitypro.com")));
//    //manager->get(QNetworkRequest(QUrl("http://emerils.com/")));

//    manager->get(QNetworkRequest(QUrl(drupalChangelog)));
//    manager->get(QNetworkRequest(QUrl(drupalJS)));

//    host = "http://bayer.ca/";
//    drupalJS = host + "misc/drupal.js";
//    drupalChangelog = host + "CHANGELOG.txt";
//    manager->get(QNetworkRequest(QUrl(drupalChangelog)));
//    manager->get(QNetworkRequest(QUrl(drupalJS)));


}

void MainWindow::replyFinished(QNetworkReply* reply)
{
    // detect drupal 7, 6? 8?
    // bach processing
    //1. check /misc/drupal.js
    //2. check www and without www
    //3. ssl support?+
    //4. /CHANGELOG.txt
    //5. X-Powered-By


    //qDebug() << reply->url().host();
    qDebug() << reply->url();
    //qDebug() << reply->rawHeaderList();
    //qDebug() << reply->rawHeader(QByteArray("Expires")); //"Sun, 19 Nov 1978 05:00:00 GMT"
    //qDebug() << reply->rawHeader(QByteArray("Location"));
    //qDebug() << reply->rawHeader(QByteArray("Content-Type"));

    int siteIndex = this->getSiteIndexByURL(reply->url());
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if (statusCode.isValid() && statusCode.toInt() == 200) {
        qDebug() << statusCode;

        if (reply->url().toString().contains("drupal.js")){
          QString javascript = reply->readAll();
          if (!javascript.contains("Drupal", Qt::CaseInsensitive)) {
              //TODO: not sure?
                    this->sites[siteIndex].isDrupal = false;
          } else {
              this->sites[siteIndex].isDrupal = true;
          }
                    qDebug() << this->sites[siteIndex].isDrupal;
        }
        if (reply->url().toString().contains("CHANGELOG.txt")){
            bool notSure = true;
            QString line = reply->readLine();
            if (line.contains("Drupal", Qt::CaseInsensitive)) {
                notSure = false;
            } else {
                int changelogCheck = 0;
                while (changelogCheck < 20) {
                    line = reply->readLine();
                    ++changelogCheck;
                    if (line.contains("Drupal", Qt::CaseInsensitive)){
                        notSure = false;
                        break;
                    }
                }
            }


            //QString line = reply->readLine();
            if (notSure) {
                QString xPoweredBy = reply->rawHeader(QByteArray("X-Powered-By"));
                //this->sites[siteIndex].drupalVersion = "not sure";
                if (!xPoweredBy.isEmpty()) {
                    this->sites[siteIndex].drupalVersion = xPoweredBy;
                }
            } else {
              line.remove(QRegExp("[\\n\\t\\r]"));
              this->sites[siteIndex].drupalVersion = line;
            }
            qDebug() << this->sites[siteIndex].drupalVersion;
        }
    } else {

        //qDebug() << this->sites[siteIndex].isDrupal;
        //qDebug() << this->sites[siteIndex].drupalVersion;
        if (statusCode.isValid()) {
            qDebug() << statusCode << "not 200";
            if (reply->url().toString().contains("CHANGELOG.txt")){
                QString xPoweredBy = reply->rawHeader(QByteArray("X-Powered-By"));
                //this->sites[siteIndex].drupalVersion = "not sure";
                this->sites[siteIndex].drupalVersion = xPoweredBy;
            }
        }
    }
    //qDebug() << reply->readAll();

    qDebug() << "----";
    reportYesNo();
    reportVersion();

    this->complete++;
    double currentProgress =  100 * ((double)this->complete/(double)this->sites.size());
    qDebug() << currentProgress / 2; //divide by two because 2 requests for each site
    ui->progressBar->setValue((int)currentProgress/2);
}

void MainWindow::copyToClipboard()
{
    QList<QTableWidgetItem*> qlist= ui->tableWidget->selectedItems();

//    clipboard->clear();

    QString text = "";

    foreach(QTableWidgetItem *item, qlist) {
//        qDebug() << item->text();
//        //TODO: OS dependent newline
//        clipboard->setText(clipboard->text() + "\n" + item->text());

        text += item->text() + "\n";
        ui->textEdit_4->setText(text);
    }

//    qDebug() << "receieved  itemselec changed signal";
}

