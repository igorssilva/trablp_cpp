#include "residencia.h"

#include <memory>

//construtor
residencia::residencia(int id, string nome, int quartos, int vagas) : imovel(id, nome)
{
    this->quartos = quartos;
    this->vagas = vagas;
}

// retorna quantidade de quartos
int residencia::getQuartos()
{
    return this->quartos;
}

// Funcao para ordenar residencias por quarto, caso os elementos não sejam todos do tipo residencia, resultados são indefinidos
bool orderByQuarto(const imovelPtr item, const imovelPtr outro)
{
    int quartosItem;
    int quartosOutro;
    // cast para residencia
    std::shared_ptr<residencia> r(std::dynamic_pointer_cast<residencia>(item));
    if (r)
    {
        quartosItem = r->getQuartos();
    }
    // cas para residencia
    std::shared_ptr<residencia> o(std::dynamic_pointer_cast<residencia>(outro));
    if (o)
    {
        quartosOutro = o->getQuartos();
    }

    if (quartosItem == quartosOutro)
    {
        return item->getId() > outro->getId();
    }

    return quartosItem > quartosOutro;
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