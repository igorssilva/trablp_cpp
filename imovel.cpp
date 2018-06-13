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
bool orderByPreco(const imovel* item, const imovel* outro)
{
    float precoItem = item->preco();
    float precoOutro = outro->preco();

    if (precoItem == precoOutro)
    {
        return item->getId() < outro->getId();
    }

    return precoItem <= precoOutro;
}

List<imovel*>* imovel::listImoveisCaros(List<imovel*> *imoveis, int perc_imoveis_caros)
{
    List<imovel*> *list = new List<imovel*>();

    int tam = imoveis->size() - (perc_imoveis_caros/100*imoveis->size());
    
    imoveis->sort(orderByPreco);

    Node<imovel*>*node = imoveis->First()

	for j < tam {
		node = node.Next()
		j += 1
	}
	j = 0
	for j < (imoveis.Size() - tam) {
		list.Add(node.Value())
		node = node.Next()
		j += 1
	}

    return list;
}


bool imovel::operator==(const imovel &i) const
{
    return this->id == (&i)->id;
}