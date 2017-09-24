/**
  * @file point.cpp
  * @version 1.4
  * @date 25/09/2017
  * @author MaironCorporation
  * @title Tratamento de poligonos
  * @brief Implementação das classes para o Tratamento de poligonos
  */

#include <iostream>
#include <cmath>
#include "point.h"
#define pi 3.14159265

using namespace std;
/**
 * @brief Point::setX Define o valor de x para a classe point
 * @param _x Representa a coordenada x do ponto
 */
void Point::setX(float _x){
    x=_x;
    }
/**
 * @brief Point::getX Recupera o valor de x para a classe point
 * @return retorna o valor
 */
float Point::getX(void){
    return x;
 }
/**
 * @brief Point::setXY Define o valor de x e y para a classe point
 * @param _x1 Representa a coordenada x do ponto
 * @param _y1 Representa a coordenada y do ponto
 */
void Point::setXY(float _x1, float _y1){
    x=_x1;
    y=_y1;
}
/**
 * @brief Point::setY Define o valor de x para a classe point
 * @param _y Representa a coordenada y do ponto
 */
void Point::setY(float _y){
    y=_y;
    }
/**
 * @brief Point::getY Recupera a coordenada y para a classe point
 * @return retorna o valor de y
 */
float Point::getY(void){
    return y;
 }
/**
 * @brief Point::add Soma os pontos e retorna outro ponto na forma(x,y) para classe point
 * @param p1 Coordenada x e y do ponto
 * @return res Retorna outra coordenada
 */
Point Point::add(Point p1){ //soma os pontos e retorna outro ponto na forma(x,y)
    Point res;     
    res.x = x + p1.x;
    res.y = y + p1.y;
    return res;
}
/**
 * @brief Point::sub Subtrai os pontos e retorna outro ponto na forma(x,y) para classe point
 * @param p1 Coordenada x e y do ponto
 * @return Retorna outra coordenada
 */
Point Point::sub(Point p1){ //subtrai os pontos e retorna outro ponto na forma(x,y)
    Point res;
    res.x = x - p1.x;
    res.y = y - p1.y;
    return res;
    }
/**
 * @brief Point::translada as coordenadas x e y adicionando os valores de a e b
 * @param a Parametro x que se quer transaladar
 * @param b Parametro y que se quer transaladar
 */
void Point::translada(float a, float b){
    x += a; y += b;
}
/**
 * @brief Point::print Imprime na classe point as coordenadas do ponto
 */
void Point::print(){
    cout << "(" << x << "," << y <<  ") ";
}
//                                        **INICIO DA PARTE POLIGONO**
/**
 * @brief Poligono::setV Define os vertices da classe poligono
 * @param _x Representa coord. x
 * @param _y Representa coord. y
 */
void Poligono::setV(float _x, float _y){
    v[nv].setX(_x);
    v[nv].setY(_y);
    nv++;
}
/**
 * @brief Poligono::getNv Recupera o valor de vertices
 * @return retorna o valor de veertices
 */
int Poligono::getNv(void){
    return nv;
}
/**
 * @brief Poligono::area Calcula a area de um poligono Regular atravéz do método de determinantes
 * @return ax Retorna a area
 */
float Poligono::area(void){
    int i;   //seta a area      //criei as variaveis a1 e a1 para calcular sua areas e depois diminuilas e dividir por 2.
    /**
     * @brief ax Area Total do poligono
     * @brief a1 Representa a primeira parte do calculo da determinante
     * @brief a2 Representa a segunda parte do calculo da determinante
     */
    float ax=0,a1=0,a2=0;

        for(i=0;i<nv-1;i++){
            a1=((v[i].getX()*v[i+1].getY())+a1);
            a2=((v[i].getY()*v[i+1].getX())+a2);
        }
        a1=(v[nv-1].getX()*v[0].getY())+a1;
        a2=(v[nv-1].getY()*v[0].getX())+a2;
        ax=(a1-a2)/2;
        return ax;
}
/**
 * @brief Poligono::translada Translada o poligono ultilizando a função da classe point
 * @param a Parametro x para transladar horizontalmente
 * @param b Parametro y para transladar verticalmente
 */
void Poligono::translada(float a, float b){
    int i;
    for(i=0;i<nv;i++){
        v[i].translada(a,b);
    }
  }
/**
 * @brief Poligono::rotaciona Rotaciona o poligono em relação a o seu centro
 * @param angulo
 */
void Poligono::rotaciona(float angulo){
    /**
     * @brief i Contador
     */
    int i;
    /**
     * @brief aux Serve para armazenar o valor de uma coordenada x, para posteriormente rotacionar
     * @brief aux2 Serve para  armazenar o valor de uma coordenada y, para posteriormente rotacionar
     */
    float aux,aux2;
    /**
     * @brief cx Serve para armazenar a coordenada x do centro do poligono
     * @brief cy Serve para armazenar a coordenada y do centro do poligono
     */
    float cx=0.0,cy=0.0;
    /**
      * @details Percorre o vetor para somar todos valores de x e y, e posteriormente dividir pelo num. de vértices e achar o centro
      */
    for(i=0;i<nv;i++){
    cx=cx + v[i].getX();
    cy=cy + v[i].getY();
    }
    cx=cx/nv;
    cy=cy/nv;
    /**
      * @details Percorre todo o vetor rotacionando e definindo novamente o valor dos parametros rotacionados
      */
    for (i=0;i<nv;i++){
        aux=v[i].getX();
        aux2=v[i].getY();
        v[i].setX(cx + (aux-cx)*cos((angulo*pi)/180)-(aux2-cy)*sin((angulo*pi)/180));
        v[i].setY(cy + (aux-cx)*sin((angulo*pi)/180)+(aux2-cy)*cos((angulo*pi)/180));
    }
  }
/**
 * @brief Poligono::imprime Chama a função print da classe point para imprimir as coordenadas
 */
void Poligono::imprime(void){
    int i;
    if(nv == 0){
        return;}
    /**
      * @details Percorre o vetor e imprime os seus valores um por um
      */
      for(i=0; i<nv-1;i++){
        v[i].print(); //chamo a print da classe point para imprimir para mim os pontos e depois imprimo um ->
        cout << "->";
      }
      v[nv-1].print();
        cout << endl;
}
//                              **Inicio da Parte Retangulo**
/**
 * @brief Retangulo::getX Recupera o valor de x para classe retangulo
 * @return retorna x
 */
float Retangulo::getX(void){
    return x;
 }
/**
 * @brief Retangulo::getY Recupera o valor de y para classe retangulo
 * @return retorna y
 */
float Retangulo::getY(void){
    return y;
 }
/**
 * @brief Retangulo::getA Recupera o valor da altura para classe retangulo
 * @return retorna a altura
 */
float Retangulo::getA(void){
    return a;
 }
/**
 * @brief Retangulo::getL Recupera o valor da largura para classe retangulo
 * @return retorna a largura
 */
float Retangulo::getL(void){
    return l;
 }
