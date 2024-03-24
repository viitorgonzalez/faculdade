#include "Pais.h"

Pais::Pais() {
    this->sigla = "";
    this->nome = "";
    this->populacao = 0;
    this->dimensaoKmQuadrado = 0;
    this->fronteiras = new string[10];
}

Pais::Pais(string sigla, string nome, int populacao, float dimensao) {
    this->sigla = sigla;
    this->nome = nome;
    this->populacao = populacao;
    this->dimensaoKmQuadrado = dimensao;
    this->fronteiras = new string[10];
}

void Pais::imprimirPais() {
    cout << this->sigla << endl << this->nome << endl << this->populacao << endl << this->dimensaoKmQuadrado << endl;
    for(int i = 0; i < 10; i++)
        cout << fronteiras[i] << "; ";
    cout << endl;
}

void Pais::verificaFronteira(string pais) {
    for(int i = 0; i < 10; i++) {
        if(fronteiras[i].compare(pais) == 0) {
            cout << "Faz fronteira\n";
            break;
        }
    }
}

float Pais::densidade() {
    return (this->populacao/this->dimensaoKmQuadrado);
}
