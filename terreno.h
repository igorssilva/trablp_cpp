#include <string>
#include "imovel.h"
using std::string;
#ifndef terreno_h
#define terreno_h

class terreno : public imovel
{
  private:
    int precoMqQd;
    string solo;

  public:
    terreno(int id, string nome, string solo, int precoMqQd);
    static bool isTerrenoArgiloso(const imovel &i);
    bool orderByArea(const terreno &item, const terreno &outro) const;
    float preco() const;
};

#endif