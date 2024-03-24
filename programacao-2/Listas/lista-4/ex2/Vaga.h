#include "Carro.cpp"

class Vaga {
    
    public:

        string data;
        int horaChegada;
        int horaSaida;
        Carro *carro;

        Vaga();

        float calculaValorTotal();
        void imprimirVaga();

};
