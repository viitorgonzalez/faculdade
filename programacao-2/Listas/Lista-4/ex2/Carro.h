#include "Proprietario.cpp"

class Carro {

    public:
        string modelo;
        string placa;
        int ano;
        Proprietario *dono;

        Carro();

        void imprimirCarro();

};
