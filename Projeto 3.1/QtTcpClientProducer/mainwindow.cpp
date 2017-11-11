#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QString>
#include <Qtimer>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
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
  strip=(ui->lineEditIP->text());
  socket->connectToHost(strip,1234);
  if(socket->waitForConnected(3000)){
    qDebug() << "Connected";
    ui->textBrowser->append("Conectado");
  }
  else{
    qDebug() << "Disconnected";
    ui->textBrowser->append("Desconectado");
  }
}

void MainWindow::putData(){
  QDateTime datetime;
  QString str;
  qint64 msecdate;

  if(socket->state()== QAbstractSocket::ConnectedState){

    msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
    str = "set "+ QString::number(msecdate) + " " + QString::number(random(ui->horizontalSliderMax->value(),ui->horizontalSliderMin->value()))+"\r\n";

      qDebug() << str;
      qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
            ui->textBrowser->append(str);

      if(socket->waitForBytesWritten(3000)){
        qDebug() << "wrote";
      }


  }
}

void MainWindow::conectar()
{
    tcpConnect();
}

int MainWindow::random(int max, int min)
{
    int _maxx;
    do{
    _maxx=(qrand()%max);

    }while(_maxx<min);
    return _maxx;
}

void MainWindow::starts()
{
    ms=(ui->horizontalSlider_3->value()*1000);
    timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(putData()));
    timer->start(ms);

}
void MainWindow::stopData(){
    timer->stop();
}
MainWindow::~MainWindow(){
  delete socket;
  delete ui;
}
