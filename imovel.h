#include <string>
#include <iostream>
#include <memory>
#include "list.h"
using std::string;
#ifndef imovel_h
#define imovel_h

typedef std::shared_ptr<imovel> imovelPtr;
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
  static List<imovelPtr> &listImoveisCaros(List<imovelPtr> &imoveis, int perc_imoveis_caros);

  //function overload
  virtual float preco() const {};
  virtual float area() const {};

  //operator overload
  virtual bool operator==(const imovel &outro) const;
  virtual imovel &operator=(const imovel &object);
};


#endif // imovel_h