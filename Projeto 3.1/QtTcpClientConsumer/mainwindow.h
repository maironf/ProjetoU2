#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void tcpConnect();
public slots:
  void getData();
  void stopData();
  void conectar();
  void starts();
private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QString s,str1;
  int ms;
  QTimer *timer;
};

#endif // MAINWINDOW_H
