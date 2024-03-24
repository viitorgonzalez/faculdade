#include "Vaga.h"

Vaga::Vaga() {
    data = "";
    horaChegada = 0;
    horaSaida = 0;
    carro = new Carro();
}

float Vaga::calculaValorTotal() {
    float total = (horaSaida - horaChegada) * 4;

    return total;
}

void Vaga::imprimirVaga() {
    cout << "Data: " << this->data << endl;
    cout << "Hora de chegada: " << this->horaChegada << endl;
    cout << "Hora de saída: " << this->horaSaida << endl;
    cout << "Detalhes do carro:" << endl;
    this->carro->imprimirCarro(); 
    cout << endl;
}
