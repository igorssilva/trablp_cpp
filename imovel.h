#include <string>
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
  //bool orderByPreco(const imovel &item, const imovel &outro);
  virtual float preco() const { return 0; };
  virtual float area() const { return 0; };
  bool operator==(const imovel &i) const;
};

#endif // imovel_h