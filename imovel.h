#include <string>
#include <iostream>
#include <memory>
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
  

  //function overload
  virtual float preco() const {};
  virtual float area() const {};

  //operator overload
  virtual bool operator==(const imovel &outro) const;
  virtual imovel &operator=(const imovel &object);
};

typedef std::shared_ptr<imovel> imovelPtr;

typedef std::shared_ptr<List<imovelPtr>> ListPtr;

ListPtr listImoveisCaros(ListPtr &imoveis, int perc_imoveis_caros);

std::function<void(const imovelPtr &i)> appendId(string &str);

#endif // imovel_h