#include "Produto.h"
#include "Categoria.h"
#include "Estoque.h"
#include <list>
#include <iostream>
#include <string>
    int Produto::proximoCOD = 1;

    Produto::Produto(const std::string& nom,const float prec, const Categoria& cat):
            codigo(proximoCOD++), nome(nom), preco(prec), categoria(cat) {}

    void Produto::mostrar(int quantidade) const{
        std::cout << *this;
        if (quantidade >= 0) {
            std::cout << " Quantidade em estoque: " << quantidade << std::endl;
        }
        std::cout << std::endl;
    }

    std::ostream& operator<<(std::ostream& os, const Produto& prod) {
        os << "--Descrição do produto--" << std::endl;
        os << " ID do produto: " << prod.codigo << std::endl;
        os << " Nome do produto: " << prod.nome << std::endl;
        os << " Preço do produto: " << prod.preco << std::endl;
        os << " Categoria: " << prod.categoria.toString() << std::endl;
        return os;
    }
    
    void Produto::setCodigo(const int cod){
        this->codigo = cod;
    }
    int Produto::getCodigo() const{
        return codigo;
    }
    
    void Produto::setNome(const std::string& nom){
        this->nome = nom;
    }
    std::string Produto::getNome() const{
        return nome;
    }
    
    void Produto::setPreco(const float prec){
        this->preco = prec;
    }
    float Produto::getPreco() const{
        return preco;
    }
    bool Produto::operator == (const Produto& prod) const{
        return prod.codigo == codigo && prod.nome == nome && prod.preco == preco;
    }
    bool Produto::operator != (const Produto& prod) const{
        return !(*this == prod);
    }
    bool Produto::operator > (const Produto& prod) const{
        if(preco > prod.getPreco())
            return true;
        else
            return false;
    }
    bool Produto::operator<(const Produto& prod) const{
        if(preco < prod.getPreco())
            return true;
        else
            return false;
    }