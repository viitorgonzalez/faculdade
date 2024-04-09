#include "Continente.h"

Continente::Continente() {
    this->nome = "";
    this->vetor = new Pais[10];
}

void Continente::inserirPais(Pais pais) {
    for(int i = 0; i < 10; i++) {
        if(vetor[i].nome == "") {
            vetor[i] = pais;
            break;
        }
    }
}

void Continente::imprimirContinente() {
    cout << this->nome << endl;
    for(int i = 0; i < 10; i++) 
        vetor[i].imprimirPais();
}

float Continente::densidade() {
    float densidade = 0;
    for(int i = 0; i < 10; i ++) {
        // Evita a divisão por zero
        if(vetor[i].nome != "")
            densidade += vetor[i].densidade();
    }
    return densidade;
}

float Continente::populacao() {
    float populacao = 0;
    for(int i = 0; i < 10; i ++) {
        if(vetor[i].nome != "")
            populacao += vetor[i].populacao;
    }
    return populacao;
}

void Continente::maiorDimensao() {
    int aux = 0;
    float maior = vetor[0].dimensaoKmQuadrado;
    for(int i = 1; i < 10; i++) {
        if(maior < vetor[i].dimensaoKmQuadrado) {
            maior = vetor[i].dimensaoKmQuadrado;
            aux = i;
        }
    }
    cout << vetor[aux].nome << endl;
}

void Continente::menorDimensao() {
    int aux = 0;
    float menor = vetor[0].dimensaoKmQuadrado;
    for(int i = 1; i < 10; i++) {
        if(menor > vetor[i].dimensaoKmQuadrado) {
            menor = vetor[i].dimensaoKmQuadrado;
            aux = i;
        }
    }
    cout << vetor[aux].nome << endl;
}
