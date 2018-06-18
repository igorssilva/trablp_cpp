#include "triangulo.h"

triangulo::triangulo(int id, string nome, string solo, int precoMqQd, float base, float altura) : terreno(id, nome, solo, precoMqQd)
{
    this->base = base;
    this->altura = altura;
}

float triangulo::area() const
{
    return (this->base * this->altura) / 2.0;
}

float triangulo::preco() const
{
    return terreno::preco() * this->area();
}

imovel &triangulo::operator=(const imovel &object)
{
    terreno::operator=(object);
    const triangulo *t = dynamic_cast<const triangulo *>(&object);
    if (t)
    {
        this->base = t->base;
        this->altura = t->altura;
    }
    return *this;
}