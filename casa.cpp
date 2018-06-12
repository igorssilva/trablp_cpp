#include "casa.h"

casa::casa(int id, string nome, int quartos, int vagas,
           int numeroPavimentos,
           float areaPavimento,
           int precoMetroQuadradoAreaPavimento,
           float areaLivre,
           int precoMetroQuadradoAreaLivre) : residencia(id, nome, quartos, vagas)
{
    this->numeroPavimentos = numeroPavimentos;
    this->areaPavimento = areaPavimento;
    this->precoMetroQuadradoAreaPavimento = precoMetroQuadradoAreaPavimento;
    this->areaLivre = areaLivre;
    this->precoMetroQuadradoAreaLivre = precoMetroQuadradoAreaLivre;
}



std::function<bool(const imovel &i)> casa::isCasaAreaPreco(float area_limite, float preco_limite)
{
    std::function<bool(const imovel &i)> clos = [area_limite, preco_limite](const imovel &i) 
    { 
        if(const casa* c = dynamic_cast<const casa*>(&i)){
            return c->area() > area_limite && c->preco() < preco_limite;
        }

        return false;
    };
    return clos;
}

float casa::preco() const
{
    return ((this->precoMetroQuadradoAreaPavimento) * this->areaPavimento * (this->numeroPavimentos)) + ((this->precoMetroQuadradoAreaLivre) * this->areaLivre);
}

float casa::area() const
{
    return this->precoMetroQuadradoAreaPavimento * this->areaPavimento;
}