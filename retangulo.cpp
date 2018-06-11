#include "retangulo.h"

retangulo::retangulo(int id, string nome, string solo, int precoMqQd, float lado1, float lado2):terreno(id, nome, solo, precoMqQd)
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