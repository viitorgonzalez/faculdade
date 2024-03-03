#ifndef EX4LIBRARY_H
#define EX4LIBRARY_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef struct BolsaValor {
  string nomeDaCompanhia;
  string areaDeAtuacao;
  float valorDaAcao;
  float valorAnterior;
  double variacaoDoValorPorcentagem;
} BolsaValor;

void preencheStruct(BolsaValor *bolsa);
void mostraStruct(BolsaValor *bolsa);
void mostraStructsAbaixo(BolsaValor *bolsa, int tam, int valor);
float retornaMedia(BolsaValor *bolsa, int tam);
float retornaDesvioPadrao(BolsaValor *bolsa, int tam);
void atualizaValor(BolsaValor *bolsa, int tam);

void preencheStruct(BolsaValor *bolsa) {
    cout << endl << "Digite o nome da companhia: ";
    getline(cin, bolsa->nomeDaCompanhia);

    cout << endl << "Digite a áre de atuação da companhia: ";
    getline(cin, bolsa->areaDeAtuacao);

    cout << endl << "Digite o valor da ação: ";
    cin >> bolsa->valorDaAcao;
    cin.ignore();

    cout << endl << "Digite o valor da variação em porcentagem: ";
    cin >> bolsa->valorAnterior;
    cin.ignore();

    cout << endl << "Digite o valor anterior da ação: ";
    cin >> bolsa->variacaoDoValorPorcentagem;
    cin.ignore();
}

void mostraStruct(BolsaValor *bolsa) {
    cout << endl << "Nome:" << bolsa->nomeDaCompanhia;
    cout << endl << "Área:" << bolsa->areaDeAtuacao;
    cout << endl << "Valor:" << bolsa->valorDaAcao;
    cout << endl << "Valor Anterior:" << bolsa->valorAnterior;
    cout << endl << "Variação:" << bolsa->variacaoDoValorPorcentagem << endl;
}

void mostraStructsAbaixo(BolsaValor *bolsa, int tam, int valor) {
  for(int i = 0; i < tam; i++)
    (bolsa[i].valorDaAcao < valor) ? mostraStruct(&bolsa[i]) : (void)0;
}

float retornaMedia(BolsaValor *bolsa, int tam) {
  float soma = 0;

  for(int i = 0; i < tam; i++) {
    soma += bolsa[i].valorDaAcao;
  }
  
  return soma / tam;
}

float retornaDesvioPadrao(BolsaValor *bolsa, int tam) {
  float media = retornaMedia(bolsa, tam);

  float somaQuadradosDiferencas = 0;
    for (int i = 0; i < tam; i++) {
        float diferenca = bolsa[i].valorDaAcao - media;
        somaQuadradosDiferencas += diferenca * diferenca;
    }

    float mediaQuadradosDiferencas = somaQuadradosDiferencas / tam;

    return sqrt(mediaQuadradosDiferencas);
}

void atualizaValor(BolsaValor *bolsa, int tam) {
  for (int i = 0; i < tam; i++) {
    bolsa[i].valorAnterior = bolsa[i]. valorDaAcao;

    bolsa[i].valorDaAcao = bolsa[i].valorAnterior * (1 + bolsa[i].variacaoDoValorPorcentagem / 100); 
  }
}

#endif 
