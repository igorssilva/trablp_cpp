#include <string>
#include "terreno.h"
using std::string;
#ifndef triangulo_h
#define triangulo_h

class triangulo : public terreno
{
  private:
    float base;
    float altura;

  public:
    triangulo(int id, string nome, string solo, int precoMqQd, float base, float altura);
    float preco() const;
    float area() const;
    imovel & operator=(const imovel & object);
};

#endif