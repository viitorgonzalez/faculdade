#include <iostream>

using namespace std;

int somaLinhasDaMatriz(int **matriz, int linhas, int colunas) {
    int soma = 0;
    
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            soma += matriz[i][j];
        }
    }

    return soma;
}

void preencherMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "Informe o valor para a posição [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

int main() {
    int linhas = 0, colunas = 0;

    cout << "Digite o número de linhas: " << endl;
    cin >> linhas;
    cin.ignore();

    cout << "Digite o número de colunas: " << endl;
    cin >> colunas;
    cin.ignore();

    int **matriz = new int*[linhas];
    for (int i = 0; i < linhas; i++) {
        matriz[i] = new int[colunas];
    }

    preencherMatriz(matriz, linhas, colunas);

    cout << somaLinhasDaMatriz(matriz, linhas, colunas);

    return 0;
}
