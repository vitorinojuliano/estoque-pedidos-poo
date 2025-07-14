#ifndef ENDERECO_H
#define ENDERECO_H

#include <iostream>
#include <string>

using namespace std;

class Endereco {
private:
    string rua, cidade, estado, cep;

public:
    Endereco(const string& rua, const string& cidade, const string& estado, const string& cep)
        : rua(rua), cidade(cidade), estado(estado), cep(cep) {}

    // Getters
    string getRua() const { 
        return rua; 
    }
    string getCidade() const { 
        return cidade; 
    }
    string getEstado() const { 
        return estado; 
    }
    string getCep() const { 
        return cep; 
    }

    // Setters
    void setRua(const string& novaRua) { 
        rua = novaRua; 
    }
    void setCidade(const string& novaCidade) { 
        cidade = novaCidade; 
    }
    void setEstado(const string& novoEstado) { 
        estado = novoEstado; 
    }
    void setCep(const string& novoCep) { 
        cep = novoCep; 
    }

    void exibirEndereco() const {
        cout <<" Rua "<< rua <<endl 
        <<" Cidade "<< cidade <<endl
        << " Estado " << estado <<endl
        << " CEP " << cep<<endl;
    }
};

#endif