#include "circulo.h"
#include "screen.h"
#include <cmath>

Circulo::Circulo(int _xc0,int _yc0,int _r,int _fillmode)
{
    xc0=_xc0;
    yc0=_yc0;
    r=_r;
    fillmode=_fillmode;
}
void Circulo::draw(Screen &t){
    double curv=0;
    double ir = 1/(double)r;
    int dx=0;
    int dy = r - 1;

    while(dx <= dy){
        t.setPixel(xc0+dy,yc0-dx);
        t.setPixel(xc0+dx,yc0-dy);
        t.setPixel(xc0-dx,yc0-dy);
        t.setPixel(xc0-dy,yc0-dx);
        t.setPixel(xc0-dy,yc0+dx);
        t.setPixel(xc0-dx,yc0+dy);
        t.setPixel(xc0+dx,yc0+dy);
        t.setPixel(xc0+dy,yc0+dx);

        dx++;
        curv += ir;
        dy = r * sin(acos(curv));
}
    if(fillmode==1){
        for(int i=xc0;i<xc0+r-1;i++){
            for(int j=yc0;j<(yc0+r-1);j++){
                       t.setPixel(i,j);
                            }
        }
        for(int i=xc0;i>xc0-r+1;i--){
            for(int j=yc0;j>(yc0-r+1);j--){
                       t.setPixel(i,j);
                            }
        }
        for(int i=xc0;i<xc0+r-1;i++){
            for(int j=yc0;j>(yc0-r+1);j--){
                       t.setPixel(i,j);
                            }
        }
        for(int i=xc0;i>xc0-r+1;i--){
            for(int j=yc0;j<(yc0+r-1);j++){
                       t.setPixel(i,j);
                            }
        }
    }


}
