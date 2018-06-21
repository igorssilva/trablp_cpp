#include <string>
#include "imovel.h"
using std::string;
#ifndef terreno_h
#define terreno_h

class terreno : public imovel
{
  // campos de terreno
private:
  int precoMtQd;
  string solo;

public:
  // construtor para todos os campos
  terreno(int id, string nome, string solo, int precoMtQd);
  // overload de preço
  float preco() const;
  // retorna o solo do terreno
  string getSolo() const;

  //operador de atribuição
  imovel &operator=(const imovel &object);
};

// retorna a lista dos menores terrenos argilosos em ordem decrescente
ListPtr listMenoresArgilosos(ListPtr &imoveis, int perc_menores_arg);

#endif