#include "imovel.h"

imovel::imovel(int id, string nome)
{
    this->id = id;
    this->nome = nome;
}

int imovel::getId() const
{
    return id;
}

//Funcao para ordenar o imovel por preço
bool orderByPreco(const imovel &item, const imovel &outro)
{
    float precoItem = item.preco();
    float precoOutro = outro.preco();

    if (precoItem == precoOutro)
    {
        return item.getId() < outro.getId();
    }

    return precoItem <= precoOutro;
}

List<imovelPtr> &imovel::listImoveisCaros(List<imovelPtr> &imoveis, int perc_imoveis_caros)
{
    List<imovelPtr> *list = new List<imovelPtr>();

    int tam = imoveis.size() - (int)((float)perc_imoveis_caros / 100 * imoveis.size());

    //imoveis.sort(orderByPreco);

    list = imoveis.slice(tam);

    return *list;
}

bool imovel::operator==(const imovel &outro) const
{
    return id == outro.getId();
}


imovel & imovel::operator=(const imovel &object)
{
    this->id = object.id;
    this->nome = object.nome;
    return *this;
}

