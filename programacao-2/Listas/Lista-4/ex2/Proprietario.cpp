#include "Proprietario.h"

Proprietario::Proprietario() {
    nome = "";
    cpf = "";
    endereco = "";
}

Proprietario::Proprietario(string nome, string cpf, string endereco) {
    this->nome = nome;    
    this->cpf = cpf;    
    this->endereco = endereco;    
}

void Proprietario::imprimirProprietario() {
    cout << this->nome << endl << this->cpf << endl << this->endereco << endl;
}
