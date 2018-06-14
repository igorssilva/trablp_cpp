#include "retangulo.h"

retangulo::retangulo(int id, string nome, string solo, int precoMqQd, float lado1, float lado2) : terreno(id, nome, solo, precoMqQd)
{
    this->lado1 = lado1;
    this->lado2 = lado2;
}

float retangulo::area() const
{
    return this->lado1 * this->lado2;
}

float retangulo::preco() const
{
    return terreno::preco() * area();
}

imovel &retangulo::operator=(const imovel &object)
{
    terreno::operator=(object);
    const retangulo *t = dynamic_cast<const retangulo *>(&object);
    if (t)
    {
        this->lado1 = t->lado1;
        this->lado2 = t->lado2;
    }

    return *this;
}