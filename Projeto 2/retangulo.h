#ifndef RETANGULO_H
#define RETANGULO_H
#include<figurageometrica.h>
/**
 * @brief The Retangulo class Serve para desenhar o retangulo
 */
class Retangulo : public FiguraGeometrica
{
private:

    int xr0,yr0,alt,larg;
public:
    /**
     * @brief Retangulo Constructor da classe retangulo
     * @param _xr0 Representa a coordenada x do ponto superior esquerdo do retangulo
     * @param _yr0 Representa a coordenada y do ponto superior esquerdo do retangulo
     * @param _alt Representa a altura do triangulo
     * @param _larg Representa a largura do triangulo
     */
    Retangulo(int _xr0,int _yr0,int _alt,int _larg);
    /**
     * @brief draw Manda instruções para se desenhar um retangulo
     * @details Usando a classe reta como apoio para formar as arestas
     * @param t Representa a nossa tela(t) na classe screen
     */
    void draw(Screen &t);
};

#endif // RETANGULO_H
