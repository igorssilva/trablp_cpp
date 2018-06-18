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

    for (int i = 1; i < 16; i++)
    {

        std::string inputFolder = "input/" + std::to_string(i) + "/";
        std::string outputFolder = "output/" + std::to_string(i) + "/";
        ListPtr imoveis = le_catalogo(inputFolder + "catalogo.txt");

        le_atual(inputFolder + "atual.txt", imoveis);

        Espec e = le_espec(inputFolder + "espec.txt");

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

        string str = str_ids_caros + str_ids_argilosos + str_ids_casas;

        // Escreve a lista de ids
        esc_string(outputFolder + "saida.txt", str_ids_caros);

        // Escreve a soma de ids
        esc_string(outputFolder + "result.txt", std::to_string(id));

        bool ret = compareFiles(inputFolder + "result.txt", outputFolder + "result.txt");
        cout << outputFolder << std::endl;
        if (ret)
        {
            cout << "result ok" << std::endl;
        }
        else
        {
            cout << "result falha" << std::endl;
        }

        ret = compareFiles(inputFolder + "saida.txt", outputFolder + "saida.txt");

        if (ret)
        {
            cout << "saida ok" << std::endl;
        }
        else
        {
            cout << "saida falha" << std::endl;
        }
    }

    return 0;
}
