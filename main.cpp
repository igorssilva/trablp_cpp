#include <iostream>
#include <memory>

#include "fileio.h"
#include "list.h"
#include "imovel.h"
#include "casa.h"
#include "terreno.h"
using std::cout;

int main(int argc, char **argv)
{

    ListPtr imoveis = le_catalogo("catalogo.txt"); // le catalogo

    le_atual("atual.txt", imoveis); // atualiza o catalogo

    Espec e = le_espec("espec.txt"); // le especificações

    int id = 0;
    imovelPtr imovel_id_index;

    // gera a lista de imoveis caros
    ListPtr imoveis_relatorio = listImoveisCaros(imoveis, e.perc_imoveis_caros);
    imovel_id_index = imoveis_relatorio->index(e.i);
    if (imovel_id_index != nullptr)
    {
        id = imovel_id_index->getId();
    }

    // Gera string de ids de imoveis caros
    string str_ids_caros = "";
    imoveis_relatorio->apply(appendId(str_ids_caros));
    str_ids_caros = str_ids_caros.substr(0, str_ids_caros.size() - 2);
    str_ids_caros.append("\n");


    // gera a lista de terrenos argilosos
    imoveis_relatorio = listMenoresArgilosos(imoveis, e.perc_menores_arg);
    imovel_id_index = imoveis_relatorio->index(e.j);
    if (imovel_id_index != nullptr)
    {
        id += imovel_id_index->getId();
    }

    // Gera string de ids de terrenos argilosos
    string str_ids_argilosos = "";
    imoveis_relatorio->apply(appendId(str_ids_argilosos));
    str_ids_argilosos = str_ids_argilosos.substr(0, str_ids_argilosos.size() - 2);
    str_ids_argilosos.append("\n");


    // gera a lista de casas
    imoveis_relatorio = listCasasAreaPreco(imoveis, e.area_limite, e.preco_limite);
    imovel_id_index = imoveis_relatorio->index(e.k);
    if (imovel_id_index != nullptr)
    {
        id += imovel_id_index->getId();
    }

    // Gera string de ids de casas
    string str_ids_casas = "";
    imoveis_relatorio->apply(appendId(str_ids_casas));
    str_ids_casas = str_ids_casas.substr(0, str_ids_casas.size() - 2);
    str_ids_casas.append("\n");


    // String de saida com todos os ids.
    string str = str_ids_caros + str_ids_argilosos + str_ids_casas;

    // Escreve a lista de ids
    esc_string("saida.txt", str);

    // Escreve a soma de ids
    esc_string("result.txt", std::to_string(id));

    cout << "Programa encerrado" << std::endl;

    return 0;
}
