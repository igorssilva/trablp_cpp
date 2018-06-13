#include <iostream>

#include "fileio.h"
#include "list.h"
using std::cout;

int main(int argc, char **argv)
{
    std::string inputFolder = "input/1/";
    List<imovel> imoveis = le_catalogo(inputFolder + "catalogo.txt");

    le_atual(inputFolder + "atual.txt", imoveis);

    Espec e = le_espec(inputFolder + "espec.txt");

    delete &imoveis;
    return 0;
}
