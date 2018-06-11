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
    imovel();
    imovel(int id, string nome);
    int getId();
    bool orderByPreco(imovel& item, imovel& outro);
    virtual float preco() { return 0; };
    virtual float area() { return 0; };
};

#endif // imovel_h