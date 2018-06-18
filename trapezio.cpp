#include "trapezio.h"

trapezio::trapezio(int id, string nome, string solo, int precoMqQd, float base1, float base2, float altura) : terreno(id, nome, solo, precoMqQd)
{
    this->base1 = base1;
    this->base2 = base2;
    this->altura = altura;
}

float trapezio::area() const
{
    return ((this->base1 + this->base2) * this->altura) / 2.0;
}

float trapezio::preco() const
{
    return terreno::preco() * this->area();
}

imovel &trapezio::operator=(const imovel &object)
{
    terreno::operator=(object);

    const trapezio *t = dynamic_cast<const trapezio *>(&object);
    if (t)
    {
        this->base1 = t->base1;
        this->base2 = t->base2;
        this->altura = t->altura;
    }

    return *this;
}