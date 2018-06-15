#include "residencia.h"

#include <memory>

residencia::residencia(int id, string nome, int quartos, int vagas) : imovel(id, nome)
{
    this->quartos = quartos;
    this->vagas = vagas;
}


int residencia::getQuartos()
{
    return this->quartos;
}

imovel &residencia::operator=(const imovel &object)
{
    imovel::operator=(object);
    const residencia *res = dynamic_cast<const residencia *>(&object);
    if (res)
    {
        this->quartos = res->quartos;
        this->vagas = res->vagas;
    }

    return *this;
}