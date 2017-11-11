#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <Qtimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
    /**
   * @brief tcpConnect Cria a conexão
   */
  void tcpConnect();
public slots:
  /**
   * @brief putData Envia os dados, com os valores da função random
   */
  void putData();
  /**
   * @brief stopData Metodo para parar o timer e assim parar de produzir dados
   */
  void stopData();
  /**
   * @brief conectar Chama a função para conectar (tcpconnect)
   */
  void conectar();
  /**
   * @brief random Calcula os numeros randomicos
   * @param max recebe o valor máximo cedido pelo usuário
   * @param min recebe o valor minimo cedido pelo usuário
   * @return
   */
  int random(int max,int min);
  /**
   * @brief starts serve para gerenciar o envio de dados. Com essa função recebo o tempo
   * e inicio um timer para chamar o metodo putdata, para funcionar no intervalo de tempo escolhido pelo usuário
   */
  void starts();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  QString s,str1;
  int ms;
  QTimer *timer;
};

#endif // MAINWINDOW_H
