/**
  * @file point.h
  * @version 1.4
  * @date 25/09/2017
  * @author MaironCorporation
  * @title Tratamento de poligonos
  * @brief Definição das classes para o Tratamento de poligonos
  */



#ifndef POINT_H
#define POINT_H
/**
 * @brief The Point class Representa pontos no espaço bidimencional
 *
 */
class Point
{
private:
    float x,y;
public:
    /**
     * @brief Point Construtor das coordenadas
     */
    Point(){
          x=0;
          y=0;
         }
    /**
     * @brief setX Define o valor da coordenada x do ponto
     * @param _x Representa a coordenada x
     */
    void setX(float _x);
    /**
     * @brief getX Recupera o valor da coordenada x do ponto
     * @return retorna este valor
     */
    float getX(void);
    /**
     * @brief setXY Define os valores das coordenadas x e y do ponto em uma mesma função
     * @param _x1 Representa a coordenada x
     * @param _y1 Representa a coordenada y
     */
    void  setXY(float _x1,float _y1);
    /**
     * @brief setY Define o valor da coordenada y do ponto
     * @param _y Representa a coordenada y
     */
    void setY(float _y);
    /**
     * @brief getY Recupera o valor da coord. y do ponto
     * @return retorna o valor
     */
    float getY(void);
    /**
     * @brief add Soma as coordenadas x e y das coordenadas do ponto p1
     * @param p1 Representa o ponto fornecido para a soma
     * @return retorna as coordenadas de um novo ponto
     */
    Point add(Point p1);
    /**
     * @brief sub Subtrai as coordenadas x e y das coordenadas do ponto p1
     * @param p1 Representa o ponto fornecido para a subtração
     * @return Retorna as coordenadas do novo ponto calculado
     */
    Point sub(Point p1);
    /**
     * @brief norma Calcula a norma, ou seja a distancia do ponto para a origem do centro de coordenadas
     * @return retorna o valor da  norma para o cliente da classe
     */
    float norma();
    /**
     * @brief translada Translada o ponto x,y para x+a e y+b
     * @param a Representa um valor para transladar a coordenada x
     * @param b Representa um valor para transladar a coordenada y
     */
    void translada(float a, float b);
    /**
     * @brief Imprime o ponto (x,y)
     */
    void print();
    /**
     * @brief Destrutor da classe ponto
     */
    ~Point(){
      }
};
/**
 * @brief The Poligono class Esta classe serve para representar poligonos convexos no espaço bidimensional
 */
class Poligono
{
private:
    int nv;
    Point v[100];
public:
    /**
     * @brief Construtor Poligono da classe
     */
    Poligono(){
          nv =0;
      }
    /**
     * @brief setV Define as coordenadas de um vértice
     * @param _x Representa coordenada x do vertice
     * @param _y Representa coordenada y do vertice
     */
    void setV(float _x, float _y);
    /**
     * @brief getNv Recupera o numero de vértices
     * @return O numero de Vertices
     */
    int getNv(void);
    /**
     * @brief area Calcula a area de um poligono
     * @return Retorna a area
     */
    float area(void);
    /**
     * @brief rotaciona Rotaciona o poligono
     * @param angulo Representa o angulo que se deseja rotacionar
     */
    void rotaciona(float angulo); //rotaciona o poligono
    /**
     * @brief translada Translada o poligono para a,b
     * @param a Representa a coordenada x a ser transladada
     * @param b Representa a coordenada y a ser transladada
     */
    void translada(float a,float b); //transala mandando para a classe point
    /**
     * @brief imprime o poligono armazenado na forma (x0,y0)->(x1,y1)...
     */
    void imprime(void); //imprime nosso poligono
    /**
      * @brief Destrutor do poligono
      */
    ~Poligono(){
    }
};
/**
 * @brief The Retangulo class Subclasse da classe derivada da superclasse Poligono que representa um retangulo no espaço bidimensional
 *
 */
class Retangulo:public Poligono{
private:
    int x,y,l,a;
public:
    /**
     * @brief Retangulo Contrutor da classe retangulo
     * @param _x Representa a coordenada x
     * @param _y Representa a coordenada y
     * @param _l Representa a largura do retangulo
     * @param _a Representa a Altura do retangulo
     */
    Retangulo(int _x=0,int _y=0,int _l=0,int _a=0){
        x=_x;
        y=_y;
        l=_l;
        a=_a;
    }
    /**
     * @brief getX Recupera a coordenada x
     * @return Retorna a coordenada x
     */
    float getX(void);
    /**
     * @brief getY Recupera a coordenada y
     * @return Retorna a coordenada x
     */
    float getY(void);
    /**
     * @brief getL Recupera a largura
     * @return Retorna a largura
     */
    float getL(void);
    /**
     * @brief getA Recupera a altura
     * @return Retorna a altura
     */
    float getA(void);
    /**
     * @brief setT Define todas as coordenadas do retangulo
     */
    void setT(void){
        setV(getX(),getY());
        setV(getL(),getY());
        setV(getL(),getA());
        setV(getX(),getA());
    }
    /**
      * @brief Destrutor da subclasse
      */
    ~Retangulo(){

    }
    };


#endif // POINT_H
