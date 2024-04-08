#include "Produto.h"
/*
Produto();
void imprimirProduto();

string getNome();
void setNome(string nome);

string getDescricao();
void setDescricao(string descricao);

float getPreco();
void setPreco(float preco);
*/

Produto::Produto() {
    this->nome = "";
    this->descricao = "";
    this->preco = 0;
}

void Produto:imprimirProduto() {
    cout << this->nome << endl << this->descricao << endl << this->preco << endl;
}
