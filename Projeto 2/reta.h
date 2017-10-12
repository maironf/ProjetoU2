#ifndef RETA_H
#define RETA_H
#include "figurageometrica.h"
/**
 * @brief The Reta class É a classe derivada da FiguraGeometrica que manda instruções para o desenho
 */
class Reta : public FiguraGeometrica
{
private:
    int x0,y0,x1,y1;
public:
    /**
     * @brief Reta
     * @param _x0 Representa a coordenada x inicial da reta
     * @param _y0 Representa a coordenada y inicial da reta
     * @param _x1 Representa a coordenada x final da reta
     * @param _y1 Representa a coordenada y final da reta
     */
    Reta(int _x0,int _y0,int _x1,int _y1);
    /**
     * @brief draw Manda instruções para classe screen desenhar a reta
     * @details Primeiramente achando as distancias entre os pontos finais e iniciais, recebendo o valor abs, para pegar o seu módulo e fazer um laço for para percorrer toda reta preenchendo-a
     * @param t Representa a tela de desenho
     */
    void draw(Screen &t);
};

#endif // RETA_H
