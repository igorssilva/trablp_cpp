#include <iostream>
#include "fileio.h"
#include "list.h"
#include "imovel.h"
#include "casa.h"
#include "terreno.h"
using std::cout;

void printPreco(const imovelPtr &im)
{
    int id = im->getId();
    float p = im->preco();    

    printf("id: %d, preco: %.2f\n", id, p);
}

void printArea(const imovelPtr &im)
{
    int id = im->getId();
    float p = im->area();    

    printf("id: %d, area: %.2f\n", id, p);
}


int main(int argc, char **argv)
{

    std::string inputFolder = "input/1/";
    ListPtr imoveis = le_catalogo(inputFolder + "catalogo.txt");

    le_atual(inputFolder + "atual.txt", imoveis);
 
    Espec e = le_espec(inputFolder + "espec.txt");

    ListPtr imoveis_caros = listImoveisCaros(imoveis, e.perc_imoveis_caros);

    imoveis_caros->apply(printPreco);
    

    return 0;
}
