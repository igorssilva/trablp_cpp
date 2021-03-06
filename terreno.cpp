#include "terreno.h"

// construtor
terreno::terreno(int id, string nome, string solo, int precoMtQd) : imovel(id, nome)
{
    this->solo = solo;
    this->precoMtQd = precoMtQd;
}

string terreno::getSolo() const
{
    return this->solo;
}



float fatorMultiplicativo(string solo)
{
    if (solo == "A")
        return 0.9;
    if (solo == "G")
        return 1.3;
    return 1.1;
}


float terreno::preco() const
{
    return this->precoMtQd * fatorMultiplicativo(this->solo);
}

imovel &terreno::operator=(const imovel &object)
{
    imovel::operator=(object);
    const terreno *t = dynamic_cast<const terreno *>(&object);
    if (t)
    {
        this->solo = t->solo;
        this->precoMtQd = t->precoMtQd;
    }

    return *this;
}


//Retorna se é um terreno argiloso
bool isTerrenoArgiloso(const imovelPtr &i)
{
    std::shared_ptr<terreno> t(std::dynamic_pointer_cast<terreno>(i));
    if (t)
    {
        bool ret = t->getSolo() == "G";
        return ret;
    }

    return false;
}


// lista dos menores terrenos argilosos em ordem decrescente
ListPtr listMenoresArgilosos(ListPtr &imoveis, int perc_menores_arg)
{    
    List<imovelPtr> *list;   

    list = imoveis->filter(isTerrenoArgiloso); // filtra terrenos argilosos
    
    list->sort(orderByArea);// ordena

    // recorta a lista
    int tam = list->size() - (int)((float)perc_menores_arg / 100 * list->size());
    List<imovelPtr> *argilosos = list->slice(tam);

    // remove a lista temporaria
    delete list;

    return ListPtr(argilosos);

}