#include <string>
#include "imovel.h"
using std::string;
#ifndef residencia_h
#define residencia_h

class residencia : public imovel
{
  // campos da residencia
private:
  int quartos;
  int vagas;

public:
  // construtor da residencia para todos os campos
  residencia(int id, string nome, int quartos, int vagas);
  // retorna quantidade de quartos da residencia
  int getQuartos();
  // operador de atribuição
  imovel &operator=(const imovel &object);
};

//  Funcao para ordenar residencias por quarto, caso os elementos não sejam todos do tipo residencia, resultados são indefinidos
bool orderByQuarto(const imovelPtr item, const imovelPtr outro);
#endif