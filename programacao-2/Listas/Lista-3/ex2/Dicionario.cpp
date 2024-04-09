#include "Dicionario.h"

Dicionario::Dicionario() {
    this->palavras = nullptr;
    this-> quantPalavra = 0;
}

void Dicionario::inserePalavra(Palavra palavra) {
    Palavra *novaLista = new Palavra("termo", 0);

    for (int i = 0; i < this->quantPalavra; i++) {
        novaLista[i] = this->palavras[i];
    }

    novaLista[this->quantPalavra] = palavra;

    delete[] this->palavras;

    this->palavras = novaLista;

    this->quantPalavra++;
}

void Dicionario::excluiPalavra(int posicao) {
    for (int i = posicao; i < this->quantPalavra - 1; i++) {
        this->palavras[i] = this->palavras[i + 1];
    }

    this->quantPalavra--;
}

void Dicionario::imprimePalavra() {
    for (int i = 0; i < this->quantPalavra; i++) {
        cout << "Palavra " << i + 1 << ": " << endl;
        cout << "Termo: " << this->palavras[i].termo << endl;
        cout << "Significados: ";

        cout << endl;
    }
}