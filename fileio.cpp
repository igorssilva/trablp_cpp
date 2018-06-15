/*Imports biblioteca padrão*/
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <memory>

/*Imports do projeto*/
#include "fileio.h"
#include "apartamento.h"
#include "casa.h"
#include "retangulo.h"
#include "trapezio.h"
#include "triangulo.h"

/*using function name*/
using std::endl;
using std::ifstream;
using std::stoi;

string getline(ifstream *in)
{
    string str;

    std::getline(*in, str);
    str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
    return str;
}


float strtof(string line)
{
    return std::stof(line);
}

imovelPtr init_item(string tipo, ifstream *in)
{
    imovelPtr im;
    string line;

    //Le id e convert para int atribuindo a variavel
    line = getline(in);
    int id = stoi(line);

    //le nome e atribui a variavel
    line = getline(in);
    string nome = line;

    if (tipo == "casa" || tipo == "apto")
    {
        //le numero de quartos
        line = getline(in);
        int quartos = stoi(line);

        //le numero de vagas
        line = getline(in);
        int vagas = stoi(line);

        if (!tipo.compare("casa"))
        {
            //le numero de pavimentos
            line = getline(in);
            int numeroPavimentos = stoi(line);

            //le area do pavimento
            line = getline(in);
            float areaPavimento = strtof(line);

            //le o preco por metro quadrado de pavimento
            line = getline(in);
            int precoMetroQuadradoAreaPavimento = stoi(line);

            //le a area livre
            line = getline(in);
            float areaLivre = strtof(line);

            //le o preco por metro quadrado livre
            line = getline(in);
            int precoMetroQuadradoAreaLivre = stoi(line);

            //upcast de casa para imovel
            casa *c = new casa(id, nome, quartos, vagas, numeroPavimentos, areaPavimento, precoMetroQuadradoAreaPavimento, areaLivre, precoMetroQuadradoAreaLivre);
            im = imovelPtr(c);
        }
        else
        {
            if (!tipo.compare("apto"))
            {
                //le o andar do apartamento
                line = getline(in);
                int andar = stoi(line);

                //le a area construida do apartamento
                line = getline(in);
                float areaConstruida = strtof(line);

                //le o preco por metro quadrado construido
                line = getline(in);
                int precoMetroQuadradoAreaConstruida = stoi(line);

                //le se contem area de lazer
                line = getline(in);
                bool lazer = line == "S";

                //le a quantidade de andares
                line = getline(in);
                int numeroAndares = stoi(line);

                //upcast de apartamento para imovel
                apartamento *apto = new apartamento(id, nome, quartos, vagas, andar, areaConstruida, precoMetroQuadradoAreaConstruida, lazer, numeroAndares);
                im = imovelPtr(apto);
            }
        }
    }
    else
    {

        //le o tipo de solo do terreno
        line = getline(in);
        string solo = line;

        //le o preco por metro quadrado do terreno
        line = getline(in);
        int precoMtQd = stoi(line);

        if (tipo == "triang")
        {
            //le a base do terreno triangular
            line = getline(in);
            float base = strtof(line);

            //le a altura do terreno triangular
            line = getline(in);
            float altura = strtof(line);

            //upcast de triangulo para imovel
            triangulo *triang = new triangulo(id, nome, solo, precoMtQd, base, altura);
            im = imovelPtr(triang);
        }
        else
        {
            if (tipo == "trapez")
            {
                //le a base1 do terreno trapezodial
                line = getline(in);
                float base1 = strtof(line);

                //le a base2 do terreno trapezodial
                line = getline(in);
                float base2 = strtof(line);

                //le a altura do terreno trapezodial
                line = getline(in);
                float altura = strtof(line);

                //upcast de trapezio para imovel
                trapezio *trapez = new trapezio(id, nome, solo, precoMtQd, base1, base2, altura);
                im = imovelPtr(trapez);
            }
            else
            {
                if (tipo == "retang")
                {
                    //le o lado1 do terreno retangular
                    line = getline(in);
                    float lado1 = strtof(line);

                    //le o lado2 do terreno retangular
                    line = getline(in);
                    float lado2 = strtof(line);

                    //upcast de retangulo para imovel
                    retangulo *retang = new retangulo(id, nome, solo, precoMtQd, lado1, lado2);
                    im = imovelPtr(retang);
                }
            }
        }
    }

    //retorna o imovel
    return im;
}

ListPtr le_catalogo(string caminho)
{
    ifstream in;
    in.open(caminho);

    //le a primeira linha com tipo
    std::string line = getline(&in);
    ListPtr imoveis = ListPtr(new List<imovelPtr>());
    while (!in.eof())
    {
        imovelPtr im = init_item(line, &in);
        imoveis->insert(im);

        //pula a linha vazia
        line = getline(&in);

        //le o proximo tipo
        line = getline(&in);
    }
    in.close();

    return imoveis;
}

void le_atual(string caminho, ListPtr &imoveis)
{
    ifstream in;
    in.open(caminho);

    //le o primeira linha com tipo
    std::string line = getline(&in);

    while (!in.eof())
    {
        //inclui um novo imovel
        if (line == "i")
        {
            line = getline(&in);
            imovelPtr im = init_item(line, &in);

            imoveis->insert(im);
        }
        else
        {
            // altera um nó
            if (line == "a")
            {
                line = getline(&in);
                imovelPtr im = init_item(line, &in);

                imoveis->changeValue(im);
            }
            else
            {
                // exclui um imovel
                if (line == "e")
                {

                    line = getline(&in);
                    imovelPtr im = imovelPtr(new imovel(stoi(line), ""));
                    imoveis->remove(im);
                }
            }
        }

        //pula a linha vazia
        line = getline(&in);

        //le o proximo tipo
        line = getline(&in);
    }

    in.close();
}

Espec le_espec(string caminho)
{
    ifstream in;
    in.open(caminho);

    std::string line;

    getline(in, line);
    int perc_imoveis_caros = stoi(line);

    getline(in, line);
    int perc_menores_arg = stoi(line);

    getline(in, line);
    float area_limite = strtof(line);

    getline(in, line);
    float preco_limite = strtof(line);

    getline(in, line);
    int i = stoi(line);

    getline(in, line);
    int j = stoi(line);

    getline(in, line);
    int k = stoi(line);

    in.close();
    Espec e = {
        perc_imoveis_caros,
        perc_menores_arg,
        area_limite,
        preco_limite,
        i,
        j,
        k,
    };
    return e;
}