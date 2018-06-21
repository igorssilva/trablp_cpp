#include <string>
#include "imovel.h"
#include "residencia.h"
using std::string;
#ifndef apartamento_h
#define apartamento_h

class apartamento : public residencia
{
  // campos do apartamento
private:
  int andar;
  float areaConstruida;
  int precoMetroQuadradoAreaConstruida;
  bool lazer;
  int numeroAndares;

public:
  //construtor para todos os campos
  apartamento(int id, string nome, int quartos, int vagas,
              int andar,
              float areaConstruida,
              int precoMetroQuadradoAreaConstruida,
              bool lazer,
              int numeroAndares);

  // preco overload
  float preco() const;

  // atribuição
  imovel &operator=(const imovel &object);
};

#endif