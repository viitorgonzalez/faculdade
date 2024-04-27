#include "Produto.cpp"

class PecaCarro : public Produto {
    private:
        string tipoCarro;
        string marca;

    public:
        PecaCarro(int codigo, string descricao, double preco, int quantidade) : Produto(codigo, descricao, preco, quantidade) {}

        PecaCarro(int codigo, string descricao, double preco, int quantidade, string tipoCarro, string marca) : Produto(codigo, descricao, preco, quantidade) {
            setTipoCarro(tipoCarro);
            setMarca(marca);
        }

        string getTipoCarro() {
            return tipoCarro;
        }

        void setTipoCarro(string tipoCarro) {
            this->tipoCarro = tipoCarro;
        }

        string getMarca() {
            return marca;
        }

        void setMarca(string marca) {
            this->marca = marca;
        }

        void imprimeProduto() {
            cout << "Código: " << getCodigo() << endl;
            cout << "Descrição: " << getDescricao() << endl;
            cout << "Preço: " << getPreco() << endl;
            cout << "Quantidade: " << getQuantidade() << endl;
            cout << "tipoCarro: " << getTipoCarro() << endl;
            cout << "marca: " << getMarca() << endl;
            cout << endl;
        }

};
