#include "ItemPedido.cpp"

class Venda {
    private:
        string cliente;
        ItemPedido itens[10];
        string data;
        float valorTotalDaVenda;
    public:
        Venda();
        void imprimirVenda();

};
