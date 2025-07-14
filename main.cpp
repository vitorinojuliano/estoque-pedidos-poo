#include <vector>
#include <stdexcept>
#include "Pedido.h"
#include "Item.h"
#include "Categoria.h"
#include "Endereco.h"
#include "Cliente.h"
#include "Fisico.h"
#include "Juridico.h"
#include "Produto.h"
#include "Estoque.h"
#include "PedidoException.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//exibirMenu
void exibirMenu(){
    std::cout << "+--------------------------------------------------+" << std::endl;
    std::cout << "|                  MENU DE OPÇÕES                  |" << std::endl;
    std::cout << "+--------------------------------------------------+" << std::endl;
    std::cout << "| 1 - Cadastrar produto                            |" << std::endl;
 
    std::cout << "| 2 - Alterar produto                              |" << std::endl;
 
    std::cout << "| 3 - Remover produto                              |" << std::endl;

    std::cout << "| 4 - Aumentar estoque de produto                  |" << std::endl;

    std::cout << "| 5 - Criar pedido                                 |" << std::endl;

    std::cout << "| 6 - Adicionar cliente                            |" << std::endl;
 
    std::cout << "| 7 - Remover item do pedido                       |" << std::endl;
 
    std::cout << "| 8 - Adicionar item a um pedido                   |" << std::endl;
 
    std::cout << "| 9 - Visualizar Produtos                          |" << std::endl;
 
    std::cout << "| 10 - Visualizar Pedidos                          |" << std::endl;

    std::cout << "| 11 - Visualizar Clientes                         |" << std::endl;

         cout << "| 12 - Visualizar Produto mais barato              |" << std::endl;

         cout << "| 13 - Visualizar Produto mais caro                |" << std::endl;

    std::cout << "| 14 - Sair                                        |" << std::endl;
    std::cout << "+--------------------------------------------------+" << std::endl;
    std::cout << "+ Escolha uma opção: " << std::endl;
    
}

void cadastrarProduto(vector<Produto>& produtos, Estoque<Produto>& estoque){
    int categoriaOpcao;
    string nome;
    float preco;
    int quantidade;

    std::cout << "INFORME:" << std::endl;
    std::cout << "Nome do produto: " << std::endl;
    cin.ignore();
    getline(cin, nome);
    std::cout << "Preço do produto: " << std::endl;
    cin >> preco;

    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << "|                 MENU DE OPÇÕES                  |" << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << "| 0 - Alimento                                    |" << std::endl;
    std::cout << "| 1 - Bebida                                      |" << std::endl;
    std::cout << "| 2 - Eletrônico                                  |" << std::endl;
    std::cout << "| 3 - Vestuário                                   |" << std::endl;
    std::cout << "| 4 - Livro                                       |" << std::endl;
    std::cout << "| 5 - Limpeza                                     |" << std::endl;
    std::cout << "| 6 - Desconhecido                                |" << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << "+ Escolha a categoria: " << std::endl;
    cin >> categoriaOpcao;
    Categoria categoria(static_cast<Categoria::Tipo>(categoriaOpcao));

    while (true) {
        try {
            std::cout << "Quantidade inicial do produto: " << std::endl;
            cin >> quantidade;
            if (quantidade < 0) {
                throw std::invalid_argument("Quantidade não pode ser negativa!");
            }
            break;
        } catch (const std::exception& e) {
            std::cout << "Erro: " << e.what() << " Tente novamente." << std::endl;
            cin.clear();
            std::cin.ignore(255, '\n');
        }
    }

    produtos.push_back(Produto(nome, preco, categoria));
    estoque.adicionarProduto(produtos.back(), quantidade);

    std::cout << "PRODUTO CADASTRADO COM SUCESSO!" << std::endl;
}

void visualizarProdutos(const vector<Produto>& produtos, const Estoque<Produto>& estoque){
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << "|              LISTA DE PRODUTOS                  |" << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    for (const auto& p : produtos){
        // Aqui uso o friend com a sobrecarga de <<
        std::cout << p;
        int qtd = estoque.getQuantidade(p.getCodigo());
        if (qtd >= 0) {
            std::cout << " Quantidade em estoque: " << qtd << std::endl;
        }
        std::cout << "+-------------------------------------------------+" << std::endl;
    }
}

int removerProdutoLista(vector<Produto>& produtos){
    int codRemover;
    std::cout << "Digite o codigo para remover produto: ";
    cin >> codRemover;
    for (auto i = produtos.begin(); i != produtos.end(); ++i) {
        if (i->getCodigo() == codRemover) {
            produtos.erase(i);
            std::cout << "PRODUTO REMOVIDO COM SUCESSO!" << std::endl;
            return codRemover;
        }
    }
    std::cout << "PRODUTO NÃO ENCONTRADO!" << std::endl;
    return -1;
}

void alterarProduto(vector<Produto>& produtos){ 
    int codAlterar;
    cout << "Digite o codigo para alterar produto: ";
    cin >> codAlterar;
    for (auto& p : produtos) {
        if (p.getCodigo() == codAlterar){
            string nome;
            float preco;
            
            std::cout << "Digite novo nome: ";
            cin.ignore();
            getline(cin, nome);
            p.setNome(nome);
            
            std::cout << "Digite novo valor: ";
            cin >> preco;
            p.setPreco(preco);
            
            std::cout << "PRODUTO ALTERADO COM SUCESSO!" << std::endl;
            return;
        }
    }
    std::cout << "PRODUTO NÃO ALTERADO!" << std::endl;
}

void criarPedido(vector<Pedido>& pedidos, vector<Produto>& produtos, vector<Cliente*>& clientes, Estoque<Produto>& estoque) {
    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        try {
            int codigoPedido;
            string nomePedido;
            cin.ignore();
            cout << "Digite o nome do pedido: ";
            getline(cin, nomePedido);

            // Selecionar cliente pelo código
            int codigoCliente;
            cout << "Digite o código do cliente: ";
            cin >> codigoCliente;

            Cliente* clienteSelecionado = nullptr;
            for (Cliente* c : clientes) {
                if (c->getCodigo() == codigoCliente) {
                    clienteSelecionado = c;
                    break;
                }
            }
            if (clienteSelecionado == nullptr) {
                throw ClienteNaoEncontradoException("Cliente não encontrado! Pedido não criado.\n");
            }

            // Criar os itens do pedido
            vector<Item> itens;
            int quantidade;

            int codProduto;
            cout << "Digite o código do produto: ";
            cin >> codProduto;

            Produto* produtoSelecionado = nullptr;
            for (auto& p : produtos) {
                if (p.getCodigo() == codProduto) {
                    produtoSelecionado = &p;
                    break;
                }
            }
            if (produtoSelecionado == nullptr) {
                throw ProdutoNaoEncontradoPedidoException("Produto não encontrado! Pedido não criado.\n");
            }

            cout << "Digite a quantidade: ";
            cin >> quantidade;

            int estoqueAtual = estoque.getQuantidade(produtoSelecionado->getCodigo());
            if (quantidade > estoqueAtual) {
                throw EstoqueInsuficienteException("Quantidade insuficiente no estoque!\n");
            }

            itens.push_back(Item(quantidade, *produtoSelecionado));
            // Atualiza o estoque
            estoque.alterarQuantidade(produtoSelecionado->getCodigo(), estoqueAtual - quantidade);
            // Criar e adicionar o pedido
            pedidos.push_back(Pedido(nomePedido, itens, clienteSelecionado));
            cout << "Pedido criado com sucesso!\n";
        } catch (const PedidoException& e) {
            cout << "Erro: " << e.what();
        }
        cout << "\nDeseja criar outro pedido? (s/n): ";
        cin >> continuar;
    }
}

void visualizarPedidos(vector<Pedido>& pedidos){
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << "|              LISTA DE PEDIDOS                   |" << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    for (const auto& ped : pedidos){
        ped.apresentar();
        std::cout << "+-------------------------------------------------+" << std::endl;
    }
}

void adicionarItemnoPedido(vector<Pedido>& pedidos, vector<Produto>& produtos, Estoque<Produto>& estoque){
    int codPedido;
    std::cout << "Informe o codigo do pedido para adicionar item: ";
    cin >> codPedido;
    for (auto& ped : pedidos) {
        if(ped.getCodigoPedido() == codPedido){
            try {
                int quantidade, codProduto;
                std::cout << "Digite o codigo do produto: ";
                cin >> codProduto;
                std::cout << "Digite a quantidade: ";
                cin >> quantidade;
                // Verifica se produto existe
                Produto* produtoSelecionado = nullptr;
                for (auto& p : produtos) {
                    if(p.getCodigo() == codProduto){
                        produtoSelecionado = &p;
                        break;
                    }
                }
                if (!produtoSelecionado) {
                    throw std::runtime_error("Produto não encontrado!");
                }
                // Verifica estoque
                int estoqueAtual = estoque.getQuantidade(produtoSelecionado->getCodigo());
                if (quantidade > estoqueAtual) {
                    throw std::runtime_error("Quantidade informada maior que o estoque disponível!");
                }
                // Verifica se produto já está no pedido
                bool itemAtualizado = false;
                for (auto& item : ped.getItens()) {
                    if (item.getProduto().getCodigo() == codProduto) {
                        // Atualiza quantidade do item
                        item.setQuantidade(item.getQuantidade() + quantidade);
                        itemAtualizado = true;
                        break;
                    }
                }
                // Desconta do estoque
                estoque.alterarQuantidade(produtoSelecionado->getCodigo(), estoqueAtual - quantidade);
                if (itemAtualizado) {
                    std::cout << "Quantidade adicionada ao item existente e estoque atualizado!" << std::endl;
                    return;
                } else {
                    // Adiciona novo item
                    Item novoItem(quantidade, *produtoSelecionado);
                    if (ped + novoItem){
                        std::cout << "PEDIDO CADASTRADO COM SUCESSO!" << std::endl;
                        return;
                    }
                }
                std::cout << "PEDIDO NÃO CADASTRADO!" << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Erro: " << e.what() << std::endl;
                return;
            }
        }
    }
}

void removerItemdoPedido(vector<Pedido>& pedidos, Estoque<Produto>& estoque) {
    int codPedido;
    std::cout << "Digite o código do pedido: ";
    std::cin >> codPedido;

    for (auto& ped : pedidos) {
        if (ped.getCodigoPedido() == codPedido) {
            int idItem;
            std::cout << "Digite o ID do item que deseja remover: ";
            std::cin >> idItem;
            // Encontrar o item e devolver ao estoque
            for (auto& item : ped.getItens()) {
                if (item.getIdItem() == idItem) {
                    int qtdAtual = estoque.getQuantidade(item.getProduto().getCodigo());
                    estoque.alterarQuantidade(item.getProduto().getCodigo(), qtdAtual + item.getQuantidade());
                    break;
                }
            }
            ped.removerItemPorId(idItem);
            return;
        }
    }

    std::cout << "PEDIDO NÃO ENCONTRADO!" << std::endl;
}

void criarCliente(vector<Cliente*>& clientes) { 
    char tipo;
    do {
        cout << "\nCadastrar cliente Fisico (f) ou Juridico (j)? ";
        cin >> tipo;
        cin.ignore(); 

        int codigo;
        string nome, rua, cidade, estado, cep;

        cout << "Codigo do cliente: ";
        cin >> codigo;
        cin.ignore();

        cout << "Nome: ";
        getline(cin, nome);
        cout << "Rua: ";
        getline(cin, rua);
        cout << "Cidade: ";
        getline(cin, cidade);
        cout << "Estado: ";
        getline(cin, estado);
        cout << "CEP: ";
        getline(cin, cep);

        if (tipo == 'f' || tipo == 'F') {
            string cpf;
            cout << "CPF (somente números): ";
            getline(cin, cpf);
            clientes.push_back(new Fisico(codigo, nome, new Endereco(rua, cidade, estado, cep), cpf));
        }
        else if (tipo == 'j' || tipo == 'J') {
            string cnpj;
            cout << "CNPJ (somente números): ";
            getline(cin, cnpj);
            clientes.push_back(new Juridico(codigo, nome, new Endereco(rua, cidade, estado, cep), cnpj));
        }
        else {
            cout << "Tipo inválido! Endereco descartado.\n";
        }

        cout << "Deseja cadastrar outro cliente? (s/n): ";
        cin >> tipo;
        cin.ignore();

    } while (tipo == 's' || tipo == 'S');
}

void mostrarClientes(const vector<Cliente*>& clientes){ 
    for (const Cliente* c: clientes){
        c->mostrarDados();
    }
}

// Função template para menor preço
template <typename T>
const T& encontrarMenorPreco(const std::vector<T>& itens) {
    if (itens.empty()) throw std::runtime_error("Lista vazia!");
    const T* menor = &itens[0];
    for (const auto& item : itens) {
        if (item.getPreco() < menor->getPreco()) {
            menor = &item;
        }
    }
    return *menor;
}

void produtoMaiorPreco(const vector<Produto>& produtos, const Estoque<Produto>& estoque){
    if (produtos.empty()) {
        std::cout << "Nenhum produto cadastrado!" << std::endl;
        return;
    }
    Produto a = produtos[0];
    for (const auto& p : produtos) {
        if (p.getPreco() > a.getPreco()) {
            a = p;
        }
    }
    a.mostrar(estoque.getQuantidade(a.getCodigo()));
}

void aumentarEstoque(vector<Produto>& produtos, Estoque<Produto>& estoque) {
    int codAlterar, quantidade;
    cout << "Digite o codigo do produto para incrementar o estoque: ";
    cin >> codAlterar;
    cout << "Digite a quantidade para incrementar o estoque: ";
    cin >> quantidade;
    // Busca produto pelo código
    Produto* produtoSelecionado = nullptr;
    for (auto& p : produtos) {
        if (p.getCodigo() == codAlterar) {
            produtoSelecionado = &p;
            break;
        }
    }
    if (produtoSelecionado && quantidade > 0) {
        estoque.adicionarProduto(*produtoSelecionado, quantidade);
        cout << "Estoque do produto incrementado em " << quantidade << " unidades." << endl;
    } else {
        cout << "Código ou quantidade inválida." << endl;
    }
}

int main(){
    vector<Produto> produtos;
    vector<Pedido> pedidos;
    vector<Cliente*> clientes;
    Estoque<Produto> estoque;
    Categoria categoriaBebida(static_cast<Categoria::Tipo>(1)); 
    Categoria categoriaAlimento(static_cast<Categoria::Tipo>(0));
    produtos.push_back(Produto("Vodka", 49.99, categoriaBebida));
    produtos.push_back(Produto("Miojo", 3.79, categoriaAlimento));
    clientes.push_back(new Fisico(12, "Juliano", new Endereco("A", "B", "C", "43312"), "837638364"));

    // Definir estoque inicial apenas via Estoque
    estoque.adicionarProduto(produtos[0], 15);
    estoque.adicionarProduto(produtos[1], 13);

    int opcao;
    do{
        exibirMenu();
        cin >> opcao;
        switch(opcao){
            case 1:
                cadastrarProduto(produtos, estoque);
                break;
            case 2:
                alterarProduto(produtos);
                break;
            case 3: {
                int cod = removerProdutoLista(produtos);
                if (cod != -1) {
                    estoque.removerProduto(cod);
                }
                break;
            }
            case 4:
                aumentarEstoque(produtos, estoque);
                break;
            case 5:
                criarPedido(pedidos, produtos, clientes, estoque);
                break;
            case 6:
                criarCliente(clientes);
                break;
            case 7:
                removerItemdoPedido(pedidos, estoque);
                break;
            case 8:
                adicionarItemnoPedido(pedidos, produtos, estoque);
                break;
            case 9:
                visualizarProdutos(produtos, estoque);
                break;
            case 10:
                visualizarPedidos(pedidos);
                break;
            case 11:
                mostrarClientes(clientes);
                break;
            case 12:
                try {
                    if (produtos.empty()) {
                        std::cout << "Nenhum produto cadastrado!" << std::endl;
                    } else {
                        const Produto& a = encontrarMenorPreco(produtos);
                        a.mostrar(estoque.getQuantidade(a.getCodigo()));
                    }
                } catch (const std::exception& e) {
                    std::cout << "Erro: " << e.what() << std::endl;
                }
                break;
            case 13:
                produtoMaiorPreco(produtos, estoque);
                break;
            case 14:
                std::cout << "Saindo..." << std::endl;
                break;
            default:
                std::cout << "Opção invalida, tente novamente." << std::endl;
                cin.clear();
                std::cin.ignore(255, '\n');
        }
    } while (opcao != 14);
    for (Cliente* c : clientes) {
        delete c;
    }
    clientes.clear();
    return 0;
}