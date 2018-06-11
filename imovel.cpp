#include "imovel.h"

imovel::imovel(int id, string nome)
{
    this->id = id;
    this->nome = nome;
}

int imovel::getId() const
{
    return this->id;
}

//Funcao para ordenar o imovel por preço
bool imovel::orderByPreco(const imovel &item, const imovel &outro)
{
    float precoItem = item.preco();
    float precoOutro = outro.preco();

    if (precoItem == precoOutro)
    {
        return item.getId() < outro.getId();
    }

    return precoItem <= precoOutro;
}

bool imovel::operator==(const imovel &i) const
{
    return this->id == (&i)->id;
}