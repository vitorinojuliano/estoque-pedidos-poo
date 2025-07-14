#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <iostream>
#include <string>

using namespace std;

class Categoria{
    public:
        enum Tipo{
            alimento,
            bebida,
            eletronico,
            vestuario,
            livro,
            limpeza
        };
        Categoria(Tipo tipo): tipoSelect(tipo) {}
        
        Categoria() : tipoSelect(){}
        
        string toString() const{
            switch (tipoSelect){
                case alimento: return "Alimento";
                case bebida: return "Bebida";
                case eletronico: return "Eletrônico";
                case vestuario: return "Vestuário";
                case livro: return "Livro";
                case limpeza: return "Limpeza";
                default: return "Desconhecido";
            }
        }
    private:
        Tipo tipoSelect;
        
};

#endif



