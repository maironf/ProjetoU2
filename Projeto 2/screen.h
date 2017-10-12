#ifndef SCREEN_H
#define SCREEN_H
#include <vector>
#include <iostream>

using namespace std;
class Screen{
private:

  // armazenam o tamanho da tela de desenho
  // no de linhas e de colunas
  int nlin, ncol;
  // guarda o caractere usado para desenhar
  char brush;
  // armazena a matriz da tela
  vector<vector<char>  > mat;
public:
  /**
   * @brief Screen Construtor da classe screen
   * @param _nlin Representa o numero de linhas
   * @param _ncol Representa o numero de colunas
   */

  Screen(int _nlin, int _ncol);


  /**
   * @brief setPixel Desenha um pixel na tela, armazenado no brush
   * @param x Representa a coordenada x do ponto
   * @param y Representa a coordenada y do ponto
   */
  void setPixel(int x, int y);


  /**
   * @brief clear Simplesmente limpa a tela
   */
  void clear();

  /**
   * @brief setBrush Serve para setar o caractere desejado para o desenho
   * @param _brush Representa o caractere escolhido
   */
  void setBrush(char _brush);

  // envia a tela para um stream de saida
  /**
   * @brief operator << Sobrecarga do operador
   * @param os representao  stream de saida
   * @param t representa a nossa tela de desenho
   * @return retorna o stream de saida
   */
  friend ostream& operator<<(ostream &os, Screen &t);
};

#endif // SCREEN_H
