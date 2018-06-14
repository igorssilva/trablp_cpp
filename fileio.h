#include <string>
#include "list.h"
#include "imovel.h"
using std::string;
#ifndef fileio_h
#define fileio_h
typedef struct
{
    int perc_imoveis_caros;
    int perc_menores_arg;
    float area_limite;
    float preco_limite;
    int i;
    int j;
    int k;
} Espec;


typedef std::shared_ptr<List<imovelPtr>> ListPtr;

ListPtr le_catalogo(string caminho);

void le_atual(string caminho, ListPtr &imoveis);

Espec le_espec(string caminho);

void esc_string(string caminho, string str);



#endif