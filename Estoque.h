
#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <list>
#include <utility>
#include <iostream>


template <typename T>
class Estoque {
private:
    std::list<std::pair<T, int>> estoqueProdutos;
public:
    void adicionarProduto(const T& item, int quantidade) {
        for (auto& par : estoqueProdutos) {
            if (par.first.getCodigo() == item.getCodigo()) {
                par.second += quantidade;
                return;
            }
        }
        estoqueProdutos.push_back(std::make_pair(item, quantidade));
    }
    bool removerProduto(int codigoItem) {
        for (auto it = estoqueProdutos.begin(); it != estoqueProdutos.end(); ++it) {
            if (it->first.getCodigo() == codigoItem) {
                estoqueProdutos.erase(it);
                return true;
            }
        }
        return false;
    }
    bool alterarQuantidade(int codigoItem, int novaQuantidade) {
        for (auto& par : estoqueProdutos) {
            if (par.first.getCodigo() == codigoItem) {
                par.second = novaQuantidade;
                return true;
            }
        }
        return false;
    }
    int getQuantidade(int codigoItem) const {
        for (const auto& par : estoqueProdutos) {
            if (par.first.getCodigo() == codigoItem) {
                return par.second;
            }
        }
        return 0;
    }
    void listarEstoque() const {
        std::cout << "Itens no estoque:\n";
        for (const auto& par : estoqueProdutos) {
            par.first.mostrar(par.second);
        }
    }
};

#endif