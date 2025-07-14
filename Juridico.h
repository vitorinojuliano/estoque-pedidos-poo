#ifndef JURIDICO_H
#define JURIDICO_H
#include <iostream>
#include <string>
using namespace std;
#include "Cliente.h"

class Juridico final: public Cliente {
private:
    string cnpj;

public:
    Juridico(int codigoCliente, const string& nomeCliente, Endereco* endereco, const string& cnpj)
        : Cliente(codigoCliente, nomeCliente, endereco), cnpj(cnpj) {}

    string getCnpj() const { return cnpj; }
    void setCnpj(const string& novoCnpj) { cnpj = novoCnpj; }

    virtual void mostrarDados() const override {
        cout<<"Cliente Juridico"<<endl;
        cout << " Codigo " << codigoCliente<<endl
             << " Nome " << nomeCliente<<endl;
        cout << " CNPJ " << cnpj << endl;
        cout<<"- Endereco -"<<endl;
        endereco->exibirEndereco();
        
    }

    virtual ~Juridico() {}
};
#endif