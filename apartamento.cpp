#include "apartamento.h"

// construtor
apartamento::apartamento(int id, string nome, int quartos, int vagas,
                         int andar,
                         float areaConstruida,
                         int precoMetroQuadradoAreaConstruida,
                         bool lazer,
                         int numeroAndares) : residencia(id, nome, quartos, vagas)
{
    this->andar = andar;
    this->areaConstruida = areaConstruida;
    this->precoMetroQuadradoAreaConstruida = precoMetroQuadradoAreaConstruida;
    this->lazer = lazer;
    this->numeroAndares = numeroAndares;
}

// retorna o preço do apartamento
float apartamento::preco() const
{
    float fatorLazer = this->lazer ? 1.15 : 1.0;
    float preco = (this->precoMetroQuadradoAreaConstruida) * this->areaConstruida * (0.9 + (float)(this->andar) / (this->numeroAndares)) * fatorLazer;

    return preco;
}

// operador de atribuição
imovel &apartamento::operator=(const imovel &object)
{
    residencia::operator=(object);

    const apartamento *apto = dynamic_cast<const apartamento *>(&object);
    if (apto)
    {
        this->andar = apto->andar;
        this->areaConstruida = apto->areaConstruida;
        this->precoMetroQuadradoAreaConstruida = apto->precoMetroQuadradoAreaConstruida;
        this->lazer = apto->lazer;
        this->numeroAndares = apto->numeroAndares;
    }

    return *this;
}
