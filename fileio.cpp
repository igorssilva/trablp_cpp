/*Imports biblioteca padrão*/
#include <fstream>
#include <algorithm>
#include <vector>
#include <locale>
#include <sstream>
#include <iostream>

/*Imports do projeto*/
#include "fileio.h"
#include "imovel.h"
#include "casa.h"
#include "apartamento.h"
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"

/*using function name*/
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::stof;
using std::stoi;
using std::vector;

imovel *init_item(string tipo, ifstream *in)
{
    imovel *im;
    string line;

    //Le id e convert para int atribuindo a variavel
    getline(*in, line);
    int id = stoi(line);

    //le nome e atribui a variavel
    getline(*in, line);
    string nome = line;

    if (tipo == "casa" || tipo == "apto")
    {
        //le numero de quartos
        getline(*in, line);
        int quartos = stoi(line);

        //le numero de vagas
        getline(*in, line);
        int vagas = stoi(line);

        if (!tipo.compare("casa"))
        {
            //le numero de pavimentos
            getline(*in, line);
            int numeroPavimentos = stoi(line);

            //le area do pavimento
            getline(*in, line);
            float areaPavimento = stof(line);

            //le o preco por metro quadrado de pavimento
            getline(*in, line);
            int precoMetroQuadradoAreaPavimento = stoi(line);

            //le a area livre
            getline(*in, line);
            float areaLivre = stof(line);

            //le o preco por metro quadrado livre
            getline(*in, line);
            int precoMetroQuadradoAreaLivre = stoi(line);

            //upcast de casa para imovel
            im = new casa(id, nome, quartos, vagas, numeroPavimentos, areaPavimento, precoMetroQuadradoAreaPavimento, areaLivre, precoMetroQuadradoAreaLivre);
        }
        else
        {
            if (!tipo.compare("apto"))
            {
                //le o andar do apartamento
                getline(*in, line);
                int andar = stoi(line);

                //le a area construida do apartamento
                getline(*in, line);
                float areaConstruida = stof(line);

                //le o preco por metro quadrado construido
                getline(*in, line);
                int precoMetroQuadradoAreaConstruida = stoi(line);

                //le se contem area de lazer
                getline(*in, line);
                bool lazer = line == "S";

                //le a quantidade de andares
                getline(*in, line);
                int numeroAndares = stoi(line);

                //upcast de apartamento para imovel
                im =new apartamento(id, nome, quartos, vagas, andar, areaConstruida, precoMetroQuadradoAreaConstruida, lazer, numeroAndares);
            }
        }
    }
    else
    {

        //le o tipo de solo do terreno
        getline(*in, line);
        string solo = line;

        //le o preco por metro quadrado do terreno
        getline(*in, line);
        int precoMtQd = stoi(line);

        if (tipo == "triang")
        {
            //le a base do terreno triangular
            getline(*in, line);
            float base = stof(line);

            //le a altura do terreno triangular
            getline(*in, line);
            float altura = stof(line);

            //upcast de triangulo para imovel
            im =new triangulo(id, nome, solo, precoMtQd, base, altura);
        }
        else
        {
            if (tipo == "trapez")
            {
                //le a base1 do terreno trapezodial
                getline(*in, line);
                float base1 = stof(line);

                //le a base2 do terreno trapezodial
                getline(*in, line);
                float base2 = stof(line);

                //le a altura do terreno trapezodial
                getline(*in, line);
                float altura = stof(line);

                //upcast de trapezio para imovel
                im =new trapezio(id, nome, solo, precoMtQd, base1, base2, altura);
            }
            else
            {
                if (tipo == "retang")
                {
                    //le o lado1 do terreno retangular
                    getline(*in, line);
                    float lado1 = stof(line);

                    //le o lado2 do terreno retangular
                    getline(*in, line);
                    float lado2 = stof(line);

                    //upcast de retangulo para imovel
                    im =new retangulo(id, nome, solo, precoMtQd, lado1, lado2);
                }
            }
        }
    }

    //retorna o imovel
    return im;
}

List<imovel> &le_catalogo(string caminho)
{
    ifstream in;
    in.open(caminho);

    std::string line;
    List<imovel> *imoveis = new List<imovel>();
    while (getline(in, line))
    {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        imovel* im = init_item(line, &in);

        std::cout << im->getId() << ": " << im->preco() << '\n';

        imoveis->insert(*im);

        //pula a linha vazia
        getline(in, line);
    }

    in.close();

    return *imoveis;
}

void le_atual(string caminho, List<imovel> &imoveis)
{
    ifstream in;
    in.open(caminho);

    std::string line;

    while (getline(in, line))
    {
        //inclui um novo imovel
        if (line == "i")
        {
            getline(in, line);
            imovel im = init_item(line, &in);

            imoveis.insert(im);
        }
        else
        {
            // altera um nó
            if (line == "a")
            {
                getline(in, line);
                imovel im = init_item(line, &in);
                imoveis.changeValue(im);
            }
            else
            {
                // exclui um imovel
                if (line == "e")
                {
                    getline(in, line);
                    imovel im = imovel(stoi(line), "");
                    imoveis.remove(im);
                }
            }
        }

        //pula a linha vazia
        getline(in, line);
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
    float area_limite = stof(line);

    getline(in, line);
    float preco_limite = stof(line);

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