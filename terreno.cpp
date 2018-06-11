#include "terreno.h"
#include <typeinfo>

terreno::terreno(int id, string nome, string solo, int precoMqQd):imovel(id, nome)
{
    this->solo = solo;
    this->precoMqQd = precoMqQd;
}

bool terreno::isTerrenoArgiloso(const imovel& i){

    if(const terreno* test = dynamic_cast<const terreno*>(&i)){
        return test->solo == "G";
    }

    return false;
}

float fatorMultiplicativo(string solo){
    if(solo == "A")
        return 0.9;
    if(solo == "G")
        return 1.3;
    return 1.1;
}

bool terreno::orderByArea(const terreno &item, const terreno &outro) const
{
    float areaItem = item.area();
    float areaOutro = outro.area();

    if (areaItem == areaOutro)
    {
        return item.getId() < outro.getId();
    }

    return areaItem <= areaOutro;
}


float terreno::preco() const
{
    return this->precoMqQd * fatorMultiplicativo(this->solo);
}