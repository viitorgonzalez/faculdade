#include <iostream>
#include <string>

#include "ex4library.h"

using namespace std;

int main() {
  int escolha = 0, tam = 0;
  double valor = 0;;
  bool sair = false;

  struct BolsaValor *acoes = new BolsaValor[30]; 
  
  do {

    cout << endl << "Digite a opção desejada: " << endl;
    cout << "1- Cadastrar" << endl;
    cout << "2- Mostrar cadastro" << endl;
    cout << "3- Mostrar cadastros abaixo do valor" << endl;
    cout << "4- Média do valor das ações cadastradas" << endl;
    cout << "5- Desvio padrão do valor das ações cadastradas" << endl;
    cout << "6- Atualizar cadastro" << endl;

    cout << "-> ";
    cin >> escolha;
    cin.ignore();


    switch (escolha) {
      case 0:
        sair = true;
        cout << endl << "Saindo...";
        break;

      case 1:
        cout << "Informe o número de ações que deseja cadastrar: ";
        cin >> tam;
        cin.ignore();

        for(int i = 0; i < tam; i++)
          preencheStruct(&acoes[i]);
        break;

      case 2:
        for(int i = 0; i < tam; i++) 
          mostraStruct(&acoes[i], tam);
        break;

      case 3:
        valor = 0;

        cout << endl << "Digite o valor de referência: ";
        cin >> valor;
        cin.ignore();

        mostraStructsAbaixo(acoes, tam, valor);
        break;

      case 4:
        cout << "Média das ações cadastradas: " << retornaMedia(acoes, tam) << endl;
        break;

      case 5:
        cout << "Desvio padrão das ações cadastradas: " << retornaDesvioPadrao(acoes, tam) << endl;
        break;

      case 6:
        atualizaValor(acoes, tam);
        break;
    }

  } while (!sair);

  return 0;
}
