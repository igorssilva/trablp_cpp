#include "residencia.h"

residencia::residencia(int id, string nome, int quartos, int vagas) : imovel(id, nome)
{
    this->quartos = quartos;
    this->vagas = vagas;
}

bool residencia::orderByQuarto(const residencia &item, const residencia &outro) const
{
    int quartosItem = (&item)->quartos;
    int quartosOutro = (&outro)->quartos;

    if (quartosItem == quartosOutro)
    {
        return item.getId() < outro.getId();
    }

    return quartosItem <= quartosOutro;
}

imovel &residencia::operator=(const imovel &object)
{
    imovel::operator=(object);
    const residencia *res = dynamic_cast<const residencia*>(&object);
    if(res)
    {
        this->quartos = res->quartos;
        this->vagas = res->vagas;
    }
   
    return *this;
}