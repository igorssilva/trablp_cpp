/*Imports biblioteca padrão*/
#include <fstream>
#include <algorithm>
#include <vector>
#include <locale>
#include <sstream>

/*Imports do projeto*/
#include "fileio.h"
#include "casa.h"
#include "apartamento.h"
#include "triangulo.h"
#include "retangulo.h"
#include "trapezio.h"

/*using function name*/
using std::getline;
using std::ifstream;
using std::istringstream;
using std::vector;

vector<string> split(const string &content, const char &c)
{
    string buff{""};
    vector<string> v;

    for (auto n : content)
    {
        if (n != c)
            buff += n;
        else if (n == c && buff != "")
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if (buff != "")
        v.push_back(buff);

    return v;
}

vector<vector<string>> create_array_file(string content)
{
    content.erase(std::remove(content.begin(), content.end(), '\r'), content.end());
    vector<string> blocks = split(content, '\n\n');
}

int strToInt(string str)
{
    std::locale brasilLocale("pt_BR.UTF-8");
    //Inicializando um conversor de string para int em pt-br
    istringstream integ;
    integ.imbue(brasilLocale);

    int i;

    integ >> i;

    return i;
}

float strToFloat(string str)
{
    std::locale brasilLocale("pt_BR.UTF-8");
    //Inicializando um conversor de string para float em pt-br
    istringstream integ;
    integ.imbue(brasilLocale);

    float i;

    integ >> i;

    return i;
}

imovel init_item(string tipo, ifstream &in)
{
    imovel im;
    string line;

    //Le id e convert para int atribuindo a variavel
    getline(in, line);
    int id = strToInt(line);

    //le nome e atribui a variavel
    getline(in, line);
    string nome = line;

    if (tipo == "casa" && tipo == "apartamento")
    {
        //le numero de quartos
        getline(in, line);
        int quartos = strToInt(line);

        //le numero de vagas
        getline(in, line);
        int vagas = strToInt(line);

        if (tipo == "casa")
        {
            //le numero de pavimentos
            getline(in, line);
            int numeroPavimentos = strToInt(line);

            //le area do pavimento
            getline(in, line);
            float areaPavimento = strToFloat(line);

            //le o preco por metro quadrado de pavimento
            getline(in, line);
            int precoMetroQuadradoAreaPavimento = strToInt(line);

            //le a area livre
            getline(in, line);
            float areaLivre = strToFloat(line);

            //le o preco por metro quadrado livre
            getline(in, line);
            int precoMetroQuadradoAreaLivre = strToInt(line);

            //upcast de casa para imovel
            im = casa(id, nome, quartos, vagas, numeroPavimentos, areaPavimento, precoMetroQuadradoAreaPavimento, areaLivre, precoMetroQuadradoAreaLivre);
        }
        else
        {
            if (tipo == "apto")
            {
                //le o andar do apartamento
                getline(in, line);
                int andar = strToInt(line);

                //le a area construida do apartamento
                getline(in, line);
                float areaConstruida = strToFloat(line);

                //le o preco por metro quadrado construido
                getline(in, line);
                int precoMetroQuadradoAreaConstruida = strToInt(line);

                //le se contem area de lazer
                getline(in, line);
                bool lazer = line == "S";

                //le a quantidade de andares
                getline(in, line);
                int numeroAndares = strToInt(line);

                //upcast de apartamento para imovel
                im = apartamento(id, nome, quartos, vagas, andar, areaConstruida, precoMetroQuadradoAreaConstruida, lazer, numeroAndares);
            }
        }
    }
    else
    {
        //le o tipo de solo do terreno
        getline(in, line);
        string solo = line;

        //le o preco por metro quadrado do terreno
        getline(in, line);
        int precoMtQd = strToInt(line);

        if (tipo == "triang")
        {
            //le a base do terreno triangular
            getline(in, line);
            float base = strToFloat(line);

            //le a altura do terreno triangular
            getline(in, line);
            float altura = strToFloat(line);

            //upcast de triangulo para imovel
            im = triangulo(id, nome, solo, precoMtQd, base, altura);
        }
        else
        {
            if (tipo == "trapez")
            {
                //le a base1 do terreno trapezodial
                getline(in, line);
                float base1 = strToFloat(line);

                //le a base2 do terreno trapezodial
                getline(in, line);
                float base2 = strToFloat(line);

                //le a altura do terreno trapezodial
                getline(in, line);
                float altura = strToFloat(line);

                //upcast de trapezio para imovel
                im = trapezio(id, nome, solo, precoMtQd, base1, base2, altura);
            }
            else
            {
                if (tipo == "retang")
                {
                    //le o lado1 do terreno retangular
                    getline(in, line);
                    float lado1 = strToFloat(line);

                    //le o lado2 do terreno retangular
                    getline(in, line);
                    float lado2 = strToFloat(line);

                    //upcast de retangulo para imovel
                    im = retangulo(id, nome, solo, precoMtQd, lado1, lado2);
                }
            }
        }
    }
    //pula a linha vazia
    getline(in, tipo);

    //retorna o imovel
    return im;
}

List<imovel> le_catalogo(string caminho)
{
    ifstream in;
    in.open(caminho);

    std::string line;
    List<imovel> imoveis = List<imovel>();
    while (getline(in, line))
    {
        imovel im = init_item(line, in);
        imoveis.insert(im);
    }

    return imoveis;
}