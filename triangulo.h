#include <string>
#include "imovel.h"
#include "terreno.h"
using std::string;
#ifndef triangulo_h
#define triangulo_h

class triangulo : public terreno
{
  // campos do triangulo
private:
  float base;
  float altura;

public:
  // construtor para todos os campos do triangulo
  triangulo(int id, string nome, string solo, int precoMqQd, float base, float altura);

  // overload funcoes
  float preco() const;
  float area() const;

  // operador de atribuição
  imovel &operator=(const imovel &object);
};

#endif