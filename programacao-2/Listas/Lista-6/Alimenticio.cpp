#include "Produto.cpp"

class Alimenticio : public Produto {
    private:
        string validade;

    public:
        Alimenticio(int codigo, string descricao, double preco, int quantidade) : Produto(codigo, descricao, preco, quantidade) {}

        Alimenticio(int codigo, string descricao, double preco, int quantidade, string validade) : Produto(codigo, descricao, preco, quantidade) {
            setValidade(validade);
        }

        string getValidade() {
            return validade;
        }

        void setValidade(string validade) {
            this->validade = validade;
        }

        void imprimeProduto() {
            cout << "Validade: " << getValidade() << endl;
            cout << endl;
        }

};
