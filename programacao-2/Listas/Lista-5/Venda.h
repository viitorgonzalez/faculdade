#include "ItemPedido.cpp"

class Venda {
    private:
        string cliente;
        ItemPedido *itens;
        string data;
        float valorTotalDaVenda;
    public:
        Venda();
        void imprimirVenda();

        string getCliente();
        void setCliente(string cliente);

        ItemPedido getItens();
        void setItens(ItemPedido *itens);

        string getData();
        void setData(string data);

        float getValorTotalDaVenda();
        void setValorTotalDaVenda(float valorTotalDaVenda);

};
