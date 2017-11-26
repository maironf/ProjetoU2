#include "harryplotter.h"
#include "mainwindow.h"
#include <QPainter>
#include <QBrush>
#include <Qpen>


HarryPlotter::HarryPlotter(QWidget *parent) : QWidget(parent)
{
    startTimer(10);

}
void HarryPlotter::getData(QVector<long> _valo){



}

void HarryPlotter::timerEvent(QTimerEvent *event)
{
 repaint();
}


void HarryPlotter::paintEvent(QPaintEvent *event){
        QPainter painter(this);
        QBrush brush;
        QPen pen;
        //brush cor amarela e solida
        brush.setColor(QColor(255,255,255));
        brush.setStyle(Qt::SolidPattern);
        //caneta cor vermelha
        pen.setColor(QColor(255,0,0));
        pen.setWidth(2);
          //informa ao pentor qual o brush atoal
        painter.setBrush(brush);
        //informa ao pintor qual canetea autal
        painter.setPen(pen);
        //desenha a borda
        painter.drawRect(0,0,width(),height());

        //desenha o grafico na tela
        pen.setColor(QColor(0,0,0));
        painter.setPen(pen);
        //linha central nao precisoa
        //painter.drawLine(0,height()/2,width(),height()/2);

        int x0,x1,y0,y1,cont;

         x0=0;
         x1=width();

         cont=0;

         for(int i=0;i<width();i+=50){
            x1 = i;
            y0 = height()- valo.value(cont)*10;
            y1 = height() - valo.value(cont+1)*10;
            if(cont>=4){
                painter.drawLine(x0,y0,x0,y0);
            }else{
            painter.drawLine(x0,y0,x1,y1);}
            x0 = x1;
            y0 = y1;
            cont++;
        }

 }


void HarryPlotter::setdados(QVector<long> _hora, QVector<long> _valo)
{
    this->hora = _hora;
    this->valo = _valo;
}
