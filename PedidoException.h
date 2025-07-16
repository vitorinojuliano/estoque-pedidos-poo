#ifndef PEDIDO_EXCEPTION_H
#define PEDIDO_EXCEPTION_H

#include <stdexcept>
#include <string>

class PedidoException : public std::runtime_error {
public:
    explicit PedidoException(const std::string& msg) : std::runtime_error(msg) {}
};

class ClienteNaoEncontradoException : public PedidoException {
public:
    explicit ClienteNaoEncontradoException(const std::string& msg)
        : PedidoException(msg) {}
};

class ProdutoNaoEncontradoPedidoException : public PedidoException {
public:
    explicit ProdutoNaoEncontradoPedidoException(const std::string& msg)
        : PedidoException(msg) {}
};

class EstoqueInsuficienteException : public PedidoException {
public:
    explicit EstoqueInsuficienteException(const std::string& msg) : PedidoException(msg) {}
};

#endif