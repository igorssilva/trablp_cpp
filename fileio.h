#include <string>
#include "list.h"
#include "imovel.h"
using std::string;
#ifndef fileio_h
#define fileio_h

// Struct de especificações
typedef struct
{
    int perc_imoveis_caros; // percentual de imoveis caros
    int perc_menores_arg;   // percentual de menores argilosos
    float area_limite;      // area limite
    float preco_limite;     // preco limite
    int i;                  // index da lista imoveis caros
    int j;                  // index da lista de menores argilosos
    int k;                  //index da lista de casas com area e preco num intervalo
} Espec;

// le o catalogo
ListPtr le_catalogo(string caminho);

// atualiza o catalogo
void le_atual(string caminho, ListPtr &imoveis);

// le o arquivo de especificacoes
Espec le_espec(string caminho);

// escreve uma string
void esc_string(string caminho, string str);

// compara dois arquivos
bool compareFiles(string entrada, string saida);

#endif