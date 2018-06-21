#include <string>
#include "imovel.h"
#include "terreno.h"
using std::string;
#ifndef trapezio_h
#define trapezio_h

class trapezio : public terreno
{
    // campos do trapezio
  private:
    float base1;
    float base2;
    float altura;

  public:
    // construtor para todos os campos do trapezio
    trapezio(int id, string nome, string solo, int precoMqQd, float base1, float base2, float altura);
    // overload funcoes
    float preco() const;
    float area() const;
    // operador de atribuição
    imovel &operator=(const imovel &object);
};

#endif