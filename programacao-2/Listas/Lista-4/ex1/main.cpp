#include "Continente.cpp"

int main() {
    Continente continente;
    Pais novoPais;

    string sigla, nome, pais;
    int populacao;
    float dimensao;

    do {
        int choice = 0;

        cout << "0- Sair" << endl; 
        cout << "1- Inserir país" << endl;
        cout << "2- Imprimir continente" << endl;
        cout << "3- Calcular densidade" << endl;
        cout << "4- Calcular população" << endl;
        cout << "5- Calcular maior dimensão" << endl;
        cout << "6- Calcular menor dimensão" << endl;
        cout << "7- Verificar fronteira" << endl;
        cout << "Digite uma opção:" << endl;
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Saindo...";
                return 0;

            case 1:
                cout << "Digite a sigla:" << endl;
                cin >> sigla;
                cout << "Digite o nome:" << endl;
                cin >> nome;
                cout << "Digite a população:" << endl;
                cin >> populacao;
                cout << "Digite a dimensão:" << endl;
                cin >> dimensao;

                novoPais = Pais(sigla, nome, populacao, dimensao);
                for(int i = 0; i < 10; i++) {
                    if(continente.nome.empty()) {
                        continente.inserirPais(novoPais);
                        break;
                    }
                }
                break;

            case 2:
                continente.imprimirContinente();
                break;

            case 3:
                cout << continente.densidade() << endl;
                break;

            case 4:
                cout << continente.populacao() << endl;
                break;
                
            case 5:
                continente.maiorDimensao();
                break;

            case 6:
                continente.menorDimensao();
                break;

            case 7:
                cout << "Digite o país pra verificar" << endl;
                cin >> pais;

                for(int i = 0; i < 10; i++) {
                    continente.vetor[i].verificaFronteira(pais);
                }
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while(true);    

    return 0;
}
