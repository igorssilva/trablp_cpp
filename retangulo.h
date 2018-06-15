#include <string>
#include "imovel.h"
#include "terreno.h"
using std::string;
#ifndef retangulo_h
#define retangulo_h

class retangulo : public terreno
{
  private:
    float lado1;
    float lado2;

  public:
    retangulo(int id, string nome, string solo, int precoMqQd, float lado1, float lado2);
    float preco() const;
    float area() const;
    imovel &operator=(const imovel &object);
};

#endif