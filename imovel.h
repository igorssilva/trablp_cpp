#include <string>
#include "list.h"
using std::string;
#ifndef imovel_h
#define imovel_h

class imovel
{
private:
  string nome;
  int id;

public:
  imovel()
  {
    this->id = 0;
    this->nome = "";
  };
  imovel(int id, string nome);
  int getId() const;
  static List<imovel*>* listImoveisCaros(List<imovel*> *imoveis, int perc_imoveis_caros);
  virtual float preco() const { return 0; };
  virtual float area() const { return 0; };
  bool operator==(const imovel &i) const;
};

#endif // imovel_h