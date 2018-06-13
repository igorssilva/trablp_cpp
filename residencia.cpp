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