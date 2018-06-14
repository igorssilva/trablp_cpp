#include <string>
#include "residencia.h"
#include <functional>
using std::string;
#ifndef casa_h
#define casa_h

class casa : public residencia
{
  private:
    int numeroPavimentos;
    float areaPavimento;
    int precoMetroQuadradoAreaPavimento;
    float areaLivre;
    int precoMetroQuadradoAreaLivre;

  public:
    casa(int id, string nome, int quartos, int vagas,
         int numeroPavimentos,
         float areaPavimento,
         int precoMetroQuadradoAreaPavimento,
         float areaLivre,
         int precoMetroQuadradoAreaLivre);
         
    std::function<bool(const imovel& i)> isCasaAreaPreco(float area_limite, float preco_limite);
    float preco() const;
    float area() const;

    imovel & operator=(const imovel & object);
};

#endif