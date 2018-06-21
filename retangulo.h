#include <string>
#include "imovel.h"
#include "terreno.h"
using std::string;
#ifndef retangulo_h
#define retangulo_h

class retangulo : public terreno
{

  // campos do retangulo
private:
  float lado1;
  float lado2;

public:
  // construtor para todos os campos do retangulo
  retangulo(int id, string nome, string solo, int precoMqQd, float lado1, float lado2);

  // overload de funcoes
  float preco() const;
  float area() const;

  // atribuição
  imovel &operator=(const imovel &object);
};

#endif