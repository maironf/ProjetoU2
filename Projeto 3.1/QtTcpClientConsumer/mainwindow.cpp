#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <Qstring>
#include <QVector>
#include <Qtimer>
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  socket = new QTcpSocket(this);

  connect(ui->pushButtonConnect,
          SIGNAL(clicked(bool)),
          this,
          SLOT(conectar()));

  connect(ui->pushButtonStart,
          SIGNAL(clicked(bool)),
          this,
          SLOT(starts()));
  connect(ui->pushButtonStop,
          SIGNAL(clicked(bool)),
          this,
          SLOT(stopData()));

}

void MainWindow::tcpConnect(){
    QString strip;
    strip=(ui->lineEdit->text());
  socket->connectToHost(strip,1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
  }
  else{
    qDebug() << "Disconnected";
  }
}

void MainWindow::getData(){
  QString str;
  QByteArray array;
  QStringList list;
  qint64 thetime;
  QVector<long> vhora,vvalor;
  qDebug() << "to get data...";
  if(socket->state() == QAbstractSocket::ConnectedState){
    if(socket->isOpen()){
      qDebug() << "reading...";
      socket->write("get 127.0.0.1 5\r\n");
      socket->waitForBytesWritten();
      socket->waitForReadyRead();
      qDebug() << socket->bytesAvailable();
      while(socket->bytesAvailable()){
        str = socket->readLine().replace("\n","").replace("\r","");
        list = str.split(" ");
        if(list.size() == 2){
          bool ok;
          str = list.at(0);
          thetime = str.toLongLong(&ok);
          vhora.push_back(thetime);
          str = list.at(1);
          vvalor.push_back(str.toLongLong(&ok));
          qDebug() << thetime << ": " << str;
        }
      }
       ui->widget->setdados(vhora,vvalor);

    }
  }
}

void MainWindow::conectar()
{
    tcpConnect();
    QString strip;
    strip=(ui->lineEdit->text());
    ui->listWidget->addItem(strip);
}

void MainWindow::starts()
{
    ms=(ui->horizontalSlider->value()*1000);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(getData()));
    timer->start(ms);

}
void MainWindow::stopData(){
    timer->stop();
}

MainWindow::~MainWindow()
{
  delete socket;
  delete ui;
}
