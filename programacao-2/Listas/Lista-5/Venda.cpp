#include "Venda.h"

Venda::Venda() {
    this->cliente = "";
    this->itens = new ItemPedido[10];
    this->data = "";
    this->valorTotalDaVenda = 0;
}

void Venda::imprimirVenda() {
    for(int i = 0; i < 10; i++)
        itens->imprimirItem();    
    cout << cliente << endl << data << endl << valorTotalDaVenda << endl;
}

string Venda::getCliente() {
    return cliente;
}

void Venda::setCliente(string cliente) {
    this->cliente = cliente;
}

ItemPedido Venda::getItens() {
    return *itens;
}

void Venda::setItens(ItemPedido *itens) {
    this->itens = itens;
}


