#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "screen.h"
#include "figurageometrica.h"
#include "circulo.h"
#include "reta.h"
#include "retangulo.h"

using namespace std;

int main()
{
    ifstream entrada;
    ofstream saida;
    string s;
    stringstream ss;
    vector <FiguraGeometrica*> figuras;
    FiguraGeometrica *pfig;
    char brus;
    int x0,y0,x1,y1;
    int xr0,yr0,alt,larg;
    int xc0,yc0,r,fillmode;
    int nlin,ncol;
    entrada.open("C:/Users/CIT/Documents/untitled3/entrada.txt");
    saida.open("C:/Users/CIT/Documents/untitled3/saida.txt");
    if(entrada.is_open()){
       cout << "Abriu o arquivo de entrada" << endl;
    }
    else {
        cout << "Ocorreu um erro " << endl;
    }
    while(entrada.good()){
        getline(entrada,s);
        if(entrada.good()){
            ss.clear();
            ss.str(s);
            while(ss.good()){
            ss >> s;
            if(s.compare(string("dim"))==0){
                ss >> nlin >> ncol;
                cout << nlin << ncol <<endl;
            }
            if(s.compare(string("brush"))==0){
                ss>> brus;
                cout << brus  <<endl;
                }
            if(s.compare(string("line"))==0){
                ss >> x0 >> y0 >> x1 >> y1;
                cout << x0 << y0 << x1 << y1 <<endl;
                figuras.push_back(new Reta(x0,y0,x1,y1));
            }

            if(s.compare(string("rectangle"))==0){
               ss >> xr0 >> yr0 >> larg >> alt;
               cout << xr0 << yr0 << larg << alt <<endl;
               figuras.push_back(new Retangulo(xr0,yr0,larg,alt));
            }
             if(s.compare(string("circulo"))==0){
               cout << "det" << endl;
               ss >> xc0 >> yc0 >> r >> fillmode;
               cout << xc0 << yc0 << r << fillmode <<endl;
               figuras.push_back(new Circulo(xc0,yc0,r,fillmode));
            }
            }
            cout << endl;
         }

    }
    Screen te(nlin,ncol);
    for(int i=0;i<figuras.size();i++){
        te.setBrush(brus);
        figuras[i]->draw(te);
     }

    if(saida.is_open()){
        saida << te;

    }else{
        cout << "Ocorreu um erro" << endl;

    }
    saida.close();



    return 0;
}
