#include "reta.h"
#define sgn(x) ((x<0)?-1:((x>0)?1:0))

Reta::Reta(int _x0, int _y0, int _x1, int _y1)
{
    x0=_x0;
    y0=_y0;
    x1=_x1;
    y1=_y1;

}
void Reta::draw(Screen &t){

        int dx, dy, dxabs, dyabs, sdx, sdy, px, py;
        float inclinacao;

        dx = x1-x0;
        dy = y1-y0;
        dxabs = abs(dx);
        dyabs = abs(dy);
        sdx = sgn(dx);
        sdy = sgn(dy);

        if (dxabs >= dyabs){
            inclinacao = (float)dy/(float)dx;
            for(int i=0;i!=dx+1;i+=sdx){
                px = x0 + i;
                py = inclinacao *i + y0;
                t.setPixel(px,py);
            }
        }
        else {
            inclinacao = (float)dx/(float)dy;
            for (int i=0;i!=dy;i+=sdy){
                px = inclinacao *i + x0;
                py = y0 + i;
                t.setPixel(px,py);
            }
        }
    }




