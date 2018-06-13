#include <iostream>

#include "fileio.h"
#include "list.h"
using std::cout;

void printPreco(const imovel *i)
{
    float p = i->preco();
    printf("id: %d, preco: %.2f\n", i->getId(), p);
}

int main(int argc, char **argv)
{
    std::string inputFolder = "input/1/";
    List<imovel*> *imoveis = le_catalogo(inputFolder + "catalogo.txt");

    le_atual(inputFolder + "atual.txt", imoveis);
    
    Espec e = le_espec(inputFolder + "espec.txt");

    List<imovel*>* imoveis_caros = imovel::listImoveisCaros(imoveis, e.perc_imoveis_caros);

    imoveis_caros->apply(printPreco);

    delete imoveis;
        return 0;
}
