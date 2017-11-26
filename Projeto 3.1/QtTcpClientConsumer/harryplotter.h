#ifndef HARRYPLOTTER_H
#define HARRYPLOTTER_H

#include <QWidget>
#include <QVector>
class HarryPlotter : public QWidget
{
    Q_OBJECT

private:
   QVector<long> hora,valo;
   int t=0;
public:
    explicit HarryPlotter(QWidget *parent = 0);
    void timerEvent(QTimerEvent *event);
    void paintEvent(QPaintEvent *event);
    void getData(QVector<long> _valo);
    void setdados(QVector<long> _hora, QVector<long> _valo);

signals:

public slots:
};

#endif // HARRYPLOTTER_H
