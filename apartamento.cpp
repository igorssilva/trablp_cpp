#include "apartamento.h"

apartamento::apartamento(int id, string nome, int quartos, int vagas,
                         int andar,
                         float areaConstruida,
                         int precoMetroQuadradoAreaConstruida,
                         bool lazer,
                         int numeroAndares) : residencia(id,nome, quartos, vagas)
{
    this->andar = andar;
    this->areaConstruida = areaConstruida;
    this->precoMetroQuadradoAreaConstruida = precoMetroQuadradoAreaConstruida;
    this->lazer = lazer;
    this->numeroAndares = numeroAndares;
}

float apartamento::preco() const
{
    float fatorLazer = this->lazer ? 1.15: 1.0;

	float preco = (this->precoMetroQuadradoAreaConstruida) * this->areaConstruida 
    * (0.9 + (this->andar)/(this->numeroAndares)) * fatorLazer;

	return preco;
}

