#ifndef PEDIDO_H
#define PEDIDO_H

#include "Item.h"
#include "Cliente.h"
#include "Fisico.h"
#include "Juridico.h"

using namespace std;
#include <vector>
#include <iostream>
#include <string>

class Pedido {
private:
    static int proximo_pedidoID;
    int pedido_codigo;
    string nome;
    vector<Item> itens;
    Cliente* cliente;

public:
    Pedido(const string& n, const vector<Item>& i, Cliente* cliente);

    void setCodigoPedido(const int c);
    int getCodigoPedido() const;

    void setTotal(const float t);
    float getTotal() const;

    void setNomePedido(const string& n);
    string getNomePedido() const;

    void apresentar() const;

    // Métodos relacionados ao item
    bool adicionarItem(const Item& i);
    void removerItemPorId(const int idItem);

    std::vector<Item>& getItens();

    bool operator+(const Item& i);
    bool operator-(const Item& i);
    Item& operator[](const int i);

};
#endif