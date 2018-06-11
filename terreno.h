#include <string>
#include "imovel.h"
using std::string;
#ifndef terreno_h
#define terreno_h

class terreno : protected imovel
{
  protected:
    int precoMqQd;
    string solo;

  public:
    terreno();
    terreno(int id);
    bool isTerrenoArgiloso();
    bool orderByArea();
    float preco();
    
};

#endif