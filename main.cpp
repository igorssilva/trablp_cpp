#include <iostream>

#include "fileio.h"
#include "apartamento.h"
#include "list.h"
using std::cout;

int main(int argc, char **argv)
{

    std::string inputFolder = "input/1/";
    ListPtr imoveis = le_catalogo(inputFolder + "catalogo.txt");

    le_atual(inputFolder + "atual.txt", imoveis);
 
    Espec e = le_espec(inputFolder + "espec.txt");

    //List<imovel*> imoveis_caros = imovel::listImoveisCaros(imoveis, e.perc_imoveis_caros);

    //imoveis_caros->apply(printPreco);

    return 0;
}
