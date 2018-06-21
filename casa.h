#include <string>
#include "imovel.h"
#include "residencia.h"
#include <functional>
using std::string;
#ifndef casa_h
#define casa_h

class casa : public residencia
{
  // campos da casa
private:
  int numeroPavimentos;
  float areaPavimento;
  int precoMetroQuadradoAreaPavimento;
  float areaLivre;
  int precoMetroQuadradoAreaLivre;

public:
// construtor de todos os campos
  casa(int id, string nome, int quartos, int vagas,
       int numeroPavimentos,
       float areaPavimento,
       int precoMetroQuadradoAreaPavimento,
       float areaLivre,
       int precoMetroQuadradoAreaLivre);
  
  // overload 
  float preco() const;
  float area() const;

  // atribuição
  imovel &operator=(const imovel &object);
};

// retorna lista de casas com area maior que a passada e preço menor que o passado
ListPtr listCasasAreaPreco(ListPtr &imoveis, float area_limite, float preco_limite);

#endif