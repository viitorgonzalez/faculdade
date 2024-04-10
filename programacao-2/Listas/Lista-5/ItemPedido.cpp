#include "ItemPedido.h"

ItemPedido::ItemPedido() {
    this->quantidade = 0;
    this->valorTotal = 0;
}

void ItemPedido::imprimirItem() {
    produto.imprimirProduto();
    cout << quantidade << endl << valorTotal << endl;
}

Produto ItemPedido::getProduto() {
    return produto;
}

void ItemPedido::setProduto(Produto produto) {
    this->produto = produto;
}

int ItemPedido::getQuantidade() {
    return quantidade;
}

void ItemPedido::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}

float ItemPedido::getValorTotal() {
    return valorTotal;
}

void ItemPedido::setValorTotal(float valorTotal) {
    this->valorTotal = valorTotal;
}
