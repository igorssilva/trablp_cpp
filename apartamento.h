#include <string>
#include "residencia.h"
using std::string;
#ifndef apartamento_h
#define apartamento_h

class apartamento : public residencia
{
  private:
    int andar;
    float areaConstruida;
    int precoMetroQuadradoAreaConstruida;
    bool lazer;
    int numeroAndares;

  public:
    apartamento(int id, string nome, int quartos, int vagas,
         int andar,
         float areaConstruida,
         int precoMetroQuadradoAreaConstruida,
         bool lazer,
         int numeroAndares);
    float preco() const;
};

#endif