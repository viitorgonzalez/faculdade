#include "Venda.cpp"

int main() {
    int tamVendas = 0, op;

    cout << "Digite o tamanho do vetor de vendas:" << endl;
    cin >> tamVendas;

    Venda *vendas = new Venda[tamVendas];

    do {
        cout << "Digite a opção:" << endl;
        cout << "0- Sair" << endl;
        cout << "1- Cadastrar venda" << endl;
        cout << "2- Imprimir uma venda" << endl;
        cout << "3- Imprimir todas as vendas" << endl;
        cout << "4- Média de todas as vendas" << endl;
        cin >> op;

        switch (op) {
            case 0:
                cout << "Saindo..." << endl;
                break;
            
            case 1:

        }

    } while (op != 0);

    return 0;
}
