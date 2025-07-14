#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>
#include "Categoria.h"

class Produto{
  private:
    static int proximoCOD;
    int codigo;
    std::string nome;
    float preco;
    Categoria categoria;

  public:
    Produto();  
    Produto(const std::string& nom, const float prec, const Categoria& cat);
    
    void mostrar(int quantidade = -1) const;
    
    void setCodigo(const int cod);
    int getCodigo() const;
    
    void setNome(const std::string& nom);
    std::string getNome() const;
    
    void setPreco(const float prec);
    float getPreco() const;
    
    void setCategoria(const Categoria& cat);
    Categoria getCategoria() const;

    bool operator == (const Produto& prod) const;
    bool operator != (const Produto& prod) const;
    bool operator > (const Produto& prod) const;
    bool operator < (const Produto& prod) const;
    Produto& operator ++ (int) ;

    friend std::ostream& operator<<(std::ostream& os, const Produto& prod);
};
#endif
