#include <iostream>
#include "Palavra.cpp"
#include "Dicionario.cpp"

using namespace std;

void mostrarMenu() {
    cout << "Menu:\n";
    cout << "1. Inserir palavra\n";
    cout << "2. Excluir palavra\n";
    cout << "3. Imprimir palavras\n";
    cout << "4. Sair\n";
    cout << "Escolha uma opção: ";
}

int main() {
    Dicionario dicionario;

    int opcao;
    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
            case 1: {
                string termo, significado;
                int quantSignificado;

                cout << "Digite o termo da palavra: ";
                cin >> termo;
                cout << "Digite a quantidade de significados: ";
                cin >> quantSignificado;

                Palavra palavra(termo, quantSignificado);

                for (int i = 0; i < quantSignificado; ++i) {
                    cout << "Digite o " << i + 1 << "º significado: ";
                    cin >> significado;
                    palavra.incluiSignificado(significado);
                }
                dicionario.inserePalavra(palavra);
                cout << "Palavra inserida com sucesso.\n";
                break;
            }
            case 2: {
                int posicao;
                cout << "Digite a posição da palavra a ser excluída: ";
                cin >> posicao;

                dicionario.excluiPalavra(posicao);
                cout << "Palavra excluída com sucesso.\n";
                break;
            }
            case 3: {
                dicionario.imprimePalavra();
                break;
            }
            case 4:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (opcao != 4);

    return 0;
}
