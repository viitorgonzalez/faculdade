#include "Produto.h"

Produto::Produto() {
    this->nome = "";
    this->descricao = "";
    this->preco = 0;
}

string Produto::getNome() {
    return nome;
}

void Produto::setNome(string nome) {
    this->nome = nome;
}

string Produto::getDescricao() {
    return descricao;
}

void Produto::setDescricao(string descricao) {
    this->descricao = descricao;
}

float Produto::getPreco() {
    return preco;
}

void Produto::setPreco(float preco) {
    this->preco = preco;
}

void Produto::imprimirProduto() {
    cout << this->nome << endl << this->descricao << endl << this->preco << endl;
}
