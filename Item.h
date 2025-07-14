#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "Produto.h"

class Item{
    private:
        static int proximoID;
        int idItem;
        int quantidade;
        float valorItem;
        Produto produto;
    public:
        Item(const int q, Produto& prod);
        void imprimir() const;
        
        void setQuantidade(const int quantidade);
        int getQuantidade() const;
        
        float getValorItem() const;
        
        int getIdItem() const;
        
        Produto getProduto() const;
};

Item operator+(Item& item, const int i);
Item operator+(const int i, Item& item);

#endif
