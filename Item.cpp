#include "Item.h"
#include "Produto.h"
#include <iostream>
int Item::proximoID = 1;

Item::Item(const int q, Produto& prod):
             idItem(proximoID++),quantidade(q), produto(prod) {
                valorItem = produto.getPreco() * quantidade;
            }

void Item::setQuantidade(const int quantidade){
    this->quantidade = quantidade;
    this->valorItem = produto.getPreco() * quantidade;
}
int Item::getQuantidade() const{
    return quantidade;
}

float Item::getValorItem() const{
    return valorItem;
}
int Item::getIdItem() const{
    return this->idItem;
}
void Item::imprimir() const{
    std::cout <<"ID do item: "<<getIdItem()<<", Quantidade: "<< getQuantidade()
    <<", Valor do pedido: "<< getValorItem()<< std::endl;
    produto.mostrar(-1); // Não é para ter acesso quando imprimir com -1
}

Produto Item::getProduto() const{
    return produto;
}

Item operator+(Item& item, const int i){
    item.setQuantidade(item.getQuantidade() + i);
    return item;
}

Item operator+(const int i, Item& item){
    item.setQuantidade(item.getQuantidade() + i);
    return item;
}