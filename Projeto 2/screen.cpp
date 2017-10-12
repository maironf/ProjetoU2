#include "screen.h"
#include "stdlib.h"
#include <iostream>
#include <vector>
using namespace std;

Screen::Screen(int _nlin, int _ncol)
{
nlin=_nlin;
ncol=_ncol;
mat.resize(nlin);
for(int i=0;i<nlin;i++){
    mat[i].resize(ncol, ' ');
}

}

void Screen::setBrush(char _brush){
    brush=_brush;
}

void Screen::setPixel(int x, int y){
    if(x<ncol && x>=0 && y<nlin && y>=0){
        mat[y][x]=brush;}
}

void Screen::clear(){
    int i,j;
    for(i=0;i<nlin;i++){
        for(j=0;j<ncol;j++){
            mat[i][j]=' ';
       }
    }
}

ostream &operator<<(ostream& os, Screen &t){
    int i,j;
    for(i = t.nlin-1; i>=0;i--){
        for(j = 0; j<t.ncol;j++){
                     os << t.mat[i][j];
        }
        os << endl;
    }
    return os;

}
