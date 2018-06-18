#include <string>
#include "imovel.h"
using std::string;
#ifndef terreno_h
#define terreno_h

class terreno : public imovel
{
private:
  int precoMtQd;
  string solo;

public:
  terreno(int id, string nome, string solo, int precoMtQd);
  float preco() const;
  string getSolo() const;
  imovel &operator=(const imovel &object);
};

ListPtr listMenoresArgilosos(ListPtr &imoveis, int perc_menores_arg);

#endif