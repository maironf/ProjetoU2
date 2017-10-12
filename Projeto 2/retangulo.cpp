#include "retangulo.h"
#include "reta.h"
Retangulo::Retangulo(int _xr0,int _yr0,int _alt,int _larg)
{
    xr0=_xr0;
    yr0=_yr0;
    alt=_alt;
    larg=_larg;
}
void Retangulo::draw(Screen &t){
    Reta r1(xr0,yr0,xr0+larg,yr0);
    Reta r2(xr0,yr0,xr0,yr0+alt);
    Reta r3(xr0,yr0+alt,xr0+larg,yr0+alt);
    Reta r4(xr0+larg,yr0,xr0+larg,yr0+alt);

    r1.draw(t);
    r2.draw(t);
    r3.draw(t);
    r4.draw(t);
}
