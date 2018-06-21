#include "imovel.h"

// construtor
imovel::imovel(int id, string nome)
{
    this->id = id;
    this->nome = nome;
}

// retorna o id do imveol
int imovel::getId() const
{
    return id;
}

// operador de igualdade 
bool imovel::operator==(const imovel &outro) const
{
    return id == outro.getId();
}

// operador de atribuição
imovel & imovel::operator=(const imovel &object)
{
    this->id = object.id;
    this->nome = object.nome;
    return *this;
}

//Funcao para ordenar o imovel por preço
bool orderByPreco(const imovelPtr item, const imovelPtr outro)
{
    float precoItem = item->preco();
    float precoOutro = outro->preco();

    if (precoItem == precoOutro)
    {
        return item->getId() < outro->getId();
    }

    return precoItem < precoOutro;
}

// Funcao para ordenar imoveis por area
bool orderByArea(const imovelPtr item, const imovelPtr outro) 
{
    float areaItem = item->area();
    float areaOutro = outro->area();

    if (areaItem == areaOutro)
    {
        return item->getId() > outro->getId();
    }

    return areaItem > areaOutro;
}


// retorna lista de imoveis caros
ListPtr listImoveisCaros(ListPtr &imoveis, int perc_imoveis_caros)
{
    List<imovelPtr> *list;

    int tam = imoveis->size() - (int)((float)perc_imoveis_caros / 100 * imoveis->size());

    imoveis->sort(orderByPreco);

    list = imoveis->slice(tam);

    return ListPtr(list);
}

// funcao para formar string de ids
std::function<void(const imovelPtr &i)> appendId(string &str)
{
      std::function<void(const imovelPtr &i)> clos = [&str](const imovelPtr &i) {
          string local = std::to_string(i->getId());
          str.append(local);
          str.append(", ");

    };
    return clos;
}