#ifndef CLIENTE
#define CLIENTE
#include <iostream>
#include <string>
#include "Endereco.h"
using namespace std;

class Cliente {
    protected:
        int codigoCliente;
        string nomeCliente;
        Endereco* endereco;
    
        Cliente(int codigoCliente, const string& nomeCliente, Endereco* endereco)
            : codigoCliente(codigoCliente), nomeCliente(nomeCliente), endereco(endereco) {}
    
    public:
        // Método puro
        virtual void mostrarDados() const = 0;
        int getCodigo() const {
            return codigoCliente;
        }
        // Destrutor virtual
        virtual ~Cliente() {
            delete endereco;
        }
};

#endif