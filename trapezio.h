#include <string>
#include "terreno.h"
using std::string;
#ifndef trapezio_h
#define trapezio_h

class trapezio : public terreno
{
    private:
        float base1;
        float base2;
        float altura;

    public:
        trapezio(int id, string nome, string solo, int precoMqQd, float base1, float base2, float altura);
        float preco() const;
        float area() const;    
        imovel & operator=(const imovel & object);
};

#endif