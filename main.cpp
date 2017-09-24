/**
  * @file main.cpp
  * @version 1.4
  * @date 25/09/2017
  * @author MaironCorporation
  * @title Tratamento de poligonos
  * @brief Programa cliente que faz uso das classes criadas
  */

#include <iostream>
#include <point.h>
#include <cmath>

using namespace std;
/**
 * @brief main faz uso e testa as classes criadas
 * @return 0 Retorna nada
 */
int main()
{
  /**
  * @brief p Objeto p é criado da classe point
  * @brief p1 Objeto p1 é criado da classe point
  * @brief p3 Objeto p3 é criado da classe point
  */
 Point p,p1,p3;
 /**
  * @brief pool Objeto pool é criado da classe poligono
  */
 Poligono pool;
 /**
  * @brief re Objeto re é criado da classe retangulo :D
  */
 Retangulo re(0.0,0.0,4.0,3.0);


 cout <<"        ####  #       ####  ####  #     #  ####  ####  #   #" << endl;
 cout <<"        #     #       #  #  #  #  #     #  #     #  #  ##  #" << endl;
 cout <<"        ####  #       ####  #  #  #     #  # ##  #  #  # # #" << endl;
 cout <<"        #     #       #     #  #  #     #  #  #  #  #  #  ##" << endl;
 cout <<"        ####  ####    #     ####  ####  #  ####  ####  #   #" << endl;


 cout <<"                    --Teste Classes Criadas--" << endl;
 re.setT();
 cout << "Coordenadas do retangulo: " << endl;
 re.imprime();
 cout << "Area Retangulo: " << re.area() << endl;
 re.translada(-3,4);
 cout << "Coordenadas do retangulo transladado: " << endl;
 re.imprime();
 cout << "Recalculando Area Retangulo Transladado: " <<re.area()<< endl;
 re.rotaciona(30);
 cout << "Coordenadas do retangulo rotacionado: " << endl;
 re.imprime();
 cout << "Recalculando Area Retangulo Rotacionado: " <<re.area()<< endl;
 return 0;
}
