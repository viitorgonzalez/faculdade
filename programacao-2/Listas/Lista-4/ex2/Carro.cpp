#include "Carro.h"

Carro::Carro() {
    modelo = "";
    placa = "";
    ano = 0;
    dono = nullptr; 
}

void Carro::imprimirCarro() {
    cout << "Modelo: " << this->modelo << endl;
    cout << "Placa: " << this->placa << endl;
    cout << "Ano: " << this->ano << endl;
    if (dono != nullptr) {
        cout << "Proprietário: " << this->dono->nome << endl;
    } else {
        cout << "Proprietário: Nenhum" << endl;
    }
}
