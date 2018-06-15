#include <memory>
#include <iostream>
#include "casa.h"

casa::casa(int id, string nome, int quartos, int vagas,
           int numeroPavimentos,
           float areaPavimento,
           int precoMetroQuadradoAreaPavimento,
           float areaLivre,
           int precoMetroQuadradoAreaLivre) : residencia(id, nome, quartos, vagas)
{
    this->numeroPavimentos = numeroPavimentos;
    this->areaPavimento = areaPavimento;
    this->precoMetroQuadradoAreaPavimento = precoMetroQuadradoAreaPavimento;
    this->areaLivre = areaLivre;
    this->precoMetroQuadradoAreaLivre = precoMetroQuadradoAreaLivre;
}

float casa::preco() const
{
    return (this->precoMetroQuadradoAreaPavimento * this->areaPavimento * this->numeroPavimentos) + (this->precoMetroQuadradoAreaLivre * this->areaLivre);
}

float casa::area() const
{
    return this->numeroPavimentos * this->areaPavimento;
}

std::function<bool(const imovelPtr &i)> isCasaAreaPreco(float area_limite, float preco_limite)
{
    std::function<bool(const imovelPtr &i)> clos = [area_limite, preco_limite](const imovelPtr &i) {
        std::shared_ptr<casa> c(dynamic_cast<casa *>(i.get()));
        if (c)
        {
            bool ret = c->area() > area_limite && c->preco() < preco_limite;
            return ret;
        }

        return false;
    };
    return clos;
}

bool orderByQuarto(const imovelPtr item, const imovelPtr outro)
{
    int quartosItem;
    int quartosOutro;
    residencia *r = dynamic_cast<residencia *>(item.get());
    if (r)
    {
        quartosItem = r->getQuartos();
    }
    residencia *o = dynamic_cast<residencia *>(outro.get());
    if (o)
    {
        quartosOutro = o->getQuartos();
    }

    if (quartosItem == quartosOutro)
    {
        return item->getId() < outro->getId();
    }

    return quartosItem <= quartosOutro;
}

ListPtr listCasasAreaPreco(ListPtr &imoveis, float area_limite, float preco_limite)
{

    List<imovelPtr> *list = imoveis->filter(isCasaAreaPreco(area_limite, preco_limite));

    list->sort(orderByQuarto);

    return ListPtr(list);
}



imovel &casa::operator=(const imovel &object)
{
    residencia::operator=(object);
    const casa *cas = dynamic_cast<const casa *>(&object);
    if (cas)
    {
        this->numeroPavimentos = cas->numeroPavimentos;
        this->areaPavimento = cas->areaPavimento;
        this->precoMetroQuadradoAreaPavimento = cas->precoMetroQuadradoAreaPavimento;
        this->areaLivre = cas->areaLivre;
        this->precoMetroQuadradoAreaLivre = cas->precoMetroQuadradoAreaLivre;
    }

    return *this;
}