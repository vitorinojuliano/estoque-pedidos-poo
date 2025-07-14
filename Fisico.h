#ifndef FISICO
#define FISICO
#include <iostream>
#include <string>
#include "Cliente.h"

using namespace std;

class Fisico final : public Cliente {
private:
    string cpf;

public:
    Fisico(int codigoCliente, const string& nomeCliente, Endereco* endereco, const string& cpf)
        : Cliente(codigoCliente, nomeCliente, endereco), cpf(cpf) {}

    string getCpf() const { return cpf; }
    void setCpf(string novoCpf) { cpf = novoCpf; }

    virtual void mostrarDados() const override {
        cout<<"Cliente Fisico"<<endl;
        cout << " Codigo " << codigoCliente<<endl
             << " Nome " << nomeCliente<<endl;
        cout << " CPF " << cpf << endl;
        cout<<"- Endereco -"<<endl;
        endereco->exibirEndereco(); 
        
    }

    virtual ~Fisico() {}
};

#endif