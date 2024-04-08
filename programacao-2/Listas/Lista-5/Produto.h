#include <iostream>
#include <string>

using namespace std;

class Produto {
    private:
        string nome;
        string descricao;
        float preco;

    public:
        Produto();
        void imprimirProduto();

        string getNome();
        void setNome(string nome);

        string getDescricao();
        void setDescricao(string descricao);

        float getPreco();
        void setPreco(float preco);

};
