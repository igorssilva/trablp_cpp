#include <string>
#include "imovel.h"
using std::string;
#ifndef residencia_h
#define residencia_h

class residencia : public imovel
{
  private:
    int quartos;
    int vagas;

  public:
    residencia(int id, string nome, int quartos, int vagas);
    bool orderByQuarto(const residencia &item, const residencia &outro) const;
};

#endif