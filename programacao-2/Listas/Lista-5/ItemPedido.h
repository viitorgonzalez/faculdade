#include "Produto.cpp"

class ItemPedido {
    private:
        Produto produto;
        int quantidade;
        float valorTotal;

    public:
        ItemPedido();
        void imprimirItem();

        Produto getProduto();
        void setProduto(Produto produto);

        int getQuantidade();
        void setQuantidade(int quantidade);

        float getValorTotal();
        void setValorTotal(float valorTotal);

};
