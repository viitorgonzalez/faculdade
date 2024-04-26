#pragma once
#include <iostream>
#include <string>

using namespace std;

class Produto {
    private:
        int codigo;
        string descricao;
        double preco;
        int quantidade;

    public:
        Produto(int codigo, string descricao, double preco, int quantidade) {
            this->codigo = codigo;
            this->descricao = descricao;
            this->preco = preco;
            this->quantidade = quantidade;
        }

        void mudaEstoque(int acrescimo) {
            quantidade += acrescimo;
        }

        void imprimeProduto() {
            cout << "Código: " << codigo << endl;
            cout << "Descrição: " << descricao << endl;
            cout << "Preço: " << preco << endl;
            cout << "Quantidade em estoque: " << quantidade << endl;
        }

        int getCodigo() {
            return codigo;
        }

        void setCodigo(int codigo) {
            this->codigo = codigo;
        }

        string getDescricao() {
            return descricao;
        }

        void setDescricao(string descricao) {
            this->descricao = descricao;
        }

        double getPreco() {
            return preco;
        }

        void setPreco(double preco) {
            this->preco = preco;
        }

        int getQuantidade() {
            return quantidade;
        }

        void setQuantidade(int quantidade) {
            this->quantidade = quantidade;
        }

};

