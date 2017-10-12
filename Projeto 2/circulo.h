#ifndef CIRCULO_H
#define CIRCULO_H
#include <figurageometrica.h>
/**
 * @brief The Circulo class Desenha um circulo, sendo ele preenchido ou não
 */
class Circulo : public FiguraGeometrica
{
private:
    int xc0,yc0,r,fillmode;
public:
    /**
     * @brief Circulo Construtor da classe circulo
     * @param _xc0 Representa a coordenada x do centro do circulo
     * @param _yc0 Representa a coordenada y do centro do circulo
     * @param _r Representa o raio do circulo
     * @param _fillmode Representa se é preenchido ou não
     */
    Circulo(int _xc0,int _yc0,int _r,int _fillmode);
    /**
     * @brief draw Este metodo manda a instrução para a classe screen desenhar o circulo
     * @details Para desenhar a borda eu calculo a distancia x e y, do centro até o raio, com um laço while preencho esses pontos, com ajuda de uma variavel curvatura para limitar o circulo
     * @param t Representa a classe screen com um ponteiro t
     */
    void draw(Screen &t);
};

#endif // CIRCULO_H
