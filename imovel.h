#include <string>
#include <iostream>
#include <memory>
#include "list.h"
using std::string;
#ifndef imovel_h
#define imovel_h

class imovel
{
  // campos de imovel
private:
  string nome;
  int id;

public:
  // construtor padrao
  imovel()
  {
    this->id = 0;
    this->nome = "";
  };
  // construtor com todos os campos
  imovel(int id, string nome);
  // retorna o id do imovel
  int getId() const;

  //function overload
  virtual float preco() const {};
  virtual float area() const {};

  //operator overload
  virtual bool operator==(const imovel &outro) const;
  virtual imovel &operator=(const imovel &object);
};

// defincao do smart pointer do imovel
typedef std::shared_ptr<imovel> imovelPtr;

// definicao do smart pointer de lista de imovel
typedef std::shared_ptr<List<imovelPtr>> ListPtr;


//Funcao para ordenar o imovel por preço
bool orderByPreco(const imovelPtr item, const imovelPtr outro);

// Funcao para ordenar imoveis por area
bool orderByArea(const imovelPtr item, const imovelPtr outro);

ListPtr listImoveisCaros(ListPtr &imoveis, int perc_imoveis_caros);

std::function<void(const imovelPtr &i)> appendId(string &str);

#endif // imovel_h