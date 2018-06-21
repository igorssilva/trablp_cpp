#include <memory>
#include <iostream>
#include "casa.h"

// construtor
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

// retorna o preço da casa
float casa::preco() const
{
    return (this->precoMetroQuadradoAreaPavimento * this->areaPavimento * this->numeroPavimentos) + (this->precoMetroQuadradoAreaLivre * this->areaLivre);
}

// retorna a area construida da casa
float casa::area() const
{
    return this->numeroPavimentos * this->areaPavimento;
}

// funcao para verificar se é uma casa e está dentro dos parametros
std::function<bool(const imovelPtr &i)> isCasaAreaPreco(float area_limite, float preco_limite)
{
    std::function<bool(const imovelPtr &i)> clos = [area_limite, preco_limite](const imovelPtr &i) {
        // veririca se o imovel é uma casa
        std::shared_ptr<casa> c(std::dynamic_pointer_cast<casa>(i));
        if (c)
        {
            bool ret = c->area() > area_limite && c->preco() < preco_limite;
            return ret;
        }

        return false;
    };
    return clos;
}

// retorna lista de casas com area superior a passada e preço inferior ao passado
ListPtr listCasasAreaPreco(ListPtr &imoveis, float area_limite, float preco_limite)
{

    List<imovelPtr> *list;
    list = imoveis->filter(isCasaAreaPreco(area_limite, preco_limite)); // filtra

    list->sort(orderByQuarto); // ordena

    return ListPtr(list);
}


// operador de atribuição
imovel &casa::operator=(const imovel &object)
{
    residencia::operator=(object);
    const casa *cas = dynamic_cast<const casa *>(&object);
    if (cas)
    {
        this->numeroPavimentos = cas->numeroPavimentos;
        this->areaPavimento = cas->areaPavimento;
        this->precoMetroQuadradoAreaPavimento = cas->precoMetroQuadradoAreaPavimento;
        this->areaLivre = cas->areaLivre;
        this->precoMetroQuadradoAreaLivre = cas->precoMetroQuadradoAreaLivre;
    }

    return *this;
}