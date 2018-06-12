#include <string>
#include "list.h"
#include "imovel.h"
using std::string;
#ifndef fileio_h
#define fileio_h

typedef struct { 
    int perc_imoveis_caros;
    int perc_menores_arg;
    float area_limite;
    float preco_limite;
    int i;
    int j;
    int k;
 } Espec;


void le_catalogo(string caminho);

void le_atual(string caminho, List<imovel>*);

Espec le_espec(string caminho);

void esc_string(string caminho, string str);

#endif