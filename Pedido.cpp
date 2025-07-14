#include "Pedido.h"
#include "Item.h"

#include "Cliente.h"



using namespace std;

int Pedido::proximo_pedidoID = 1;

Pedido::Pedido(const string& n, const vector<Item>& i, Cliente* cliente)
    : pedido_codigo(proximo_pedidoID++), nome(n), itens(i), cliente(cliente) {}

void Pedido::setCodigoPedido(const int c){
    pedido_codigo = c;
}
int Pedido::getCodigoPedido() const{
    return pedido_codigo;
}

// mudado
std::vector<Item>& Pedido::getItens() {
    return itens;
}

void Pedido::setNomePedido(const string& n){
    nome = n;
}
string Pedido::getNomePedido() const{
    return nome;
}

// ATUALIZADO
void Pedido::apresentar() const {
    std::cout << "-------PRINTANDO PEDIDO-------" << std::endl;
    std::cout << "Codigo do pedido: " << pedido_codigo << ", Nome: " << nome << std::endl;
    
    std::cout << "Cliente: " << endl;
    cliente->mostrarDados();

    std::cout << endl << "Itens do pedido: " << std::endl;
    
    float total = 0;

    for (const Item& i : itens){
        i.imprimir();
        total += i.getValorItem();
    }
    std::cout << "Valor total do pedido: " << total << std::endl << endl;
}


// Métodos relacionados a item
void Pedido::removerItemPorId(int idItem) {
    for (auto it = itens.begin(); it != itens.end(); ++it) {
        if (it->getIdItem() == idItem) {
            itens.erase(it);
            std::cout << "ITEM REMOVIDO COM SUCESSO!" << std::endl;
            return;
        }
    }
    std::cout << "ITEM NÃO ENCONTRADO NO PEDIDO!" << std::endl;
}

bool Pedido::adicionarItem(const Item& i){
    for(auto& itens_for : itens ){
        if(itens_for.getProduto() == i.getProduto()){
            cout << "Produto já existente no pedido" << endl;
            return false;
        }
    }
    itens.push_back(i);
    return true;
}

bool Pedido::operator+(const Item& i){
    return adicionarItem(i);
}

bool Pedido::operator-(const Item& i){
    removerItemPorId(i.getIdItem());
    return true;
}

Item& Pedido::operator[](const int i){
    return itens[i];
}