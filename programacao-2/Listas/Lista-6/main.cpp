#include <iostream>
#include "Livro.cpp"
#include "Alimenticio.cpp"
#include "PecaCarro.cpp"

using namespace std;

const int SIZE = 5;

int main() {
    Livro* livros[SIZE] = {nullptr}; 
    Alimenticio* alimenticios[SIZE] = {nullptr}; 
    PecaCarro* pecas[SIZE] = {nullptr};
    int codigoToIndex[SIZE] = {-1};
    int contador = 0; 

    int opcao, op, codigo, quantidade, numeroPaginas;
    double preco, valorTotal;
    string descricao, autor, validade, tipoCarro, marca;

    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Criar um produto" << endl;
        cout << "2. Mudar estoque de um produto" << endl;
        cout << "3. Calcular valor total em estoque de um produto" << endl;
        cout << "4. Imprimir todos os produtos de um tipo" << endl;
        cout << "5. Imprimir todos os produtos cadastrados de todos os tipos" << endl;
        cout << "0. Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;
        
        switch (opcao) {
            // Criar produto
            case 1:
                if (contador >= SIZE) {
                    cout << "Limite de produtos alcançado!" << endl;
                    break;
                }

                cout << "Digite o código do produto:" << endl;
                cin >> codigo;

                // Verificar se o código já está em uso
                if (codigoToIndex[codigo] != -1) {
                    cout << "Código de produto já em uso!" << endl;
                    break;
                }

                cout << "Digite a descrição do produto:" << endl;
                cin.ignore(); // Limpa o buffer do teclado
                getline(cin, descricao);
                cout << "Digite o preço do produto:" << endl;
                cin >> preco;
                cout << "Digite a quantidade do produto:" << endl;
                cin >> quantidade;

                cout << "Escolha o produto: (1- Livro; 2- Alimentício; 3- Peça de Carro)" << endl;
                cin >> op; 

                switch(op) {
                    case 1:
                        cout << "Digite o nome do autor:" << endl;
                        cin.ignore(); // Limpa o buffer do teclado
                        getline(cin, autor);
                        cout << "Digite o número de páginas:" << endl;
                        cin >> numeroPaginas;

                        livros[contador] = new Livro(codigo, descricao, preco, quantidade, autor, numeroPaginas);
                        codigoToIndex[codigo] = contador;
                        contador++;
                        cout << "Livro cadastrado!" << endl;
                        break;
                    case 2:
                        cout << "Digite a data de validade:" << endl;
                        cin.ignore(); // Limpa o buffer do teclado
                        getline(cin, validade);

                        alimenticios[contador] = new Alimenticio(codigo, descricao, preco, quantidade, validade);
                        codigoToIndex[codigo] = contador;
                        contador++;
                        cout << "Alimentício cadastrado!" << endl;
                        break;
                    case 3:
                        cout << "Digite o tipo de carro:" << endl;
                        cin.ignore(); // Limpa o buffer do teclado
                        getline(cin, tipoCarro);
                        cout << "Digite a marca do carro:" << endl;
                        cin.ignore(); // Limpa o buffer do teclado
                        getline(cin, marca);

                        pecas[contador] = new PecaCarro(codigo, descricao, preco, quantidade, tipoCarro, marca);
                        codigoToIndex[codigo] = contador;
                        contador++;
                        cout << "Peça de Carro cadastrada!" << endl;
                        break;
                    default:
                        cout << "Opção inválida!" << endl;
                        break;
                }
                break;
            // Mudar estoque
            case 2:
                cout << "Digite o código do produto:" << endl;
                cin >> codigo;
                cout << "Digite a quantidade a ser acrescentada ou subtraída:" << endl;
                int acrescimo;
                cin >> acrescimo;

                // Verificar se o código é válido
                if (codigo >= 0 && codigo < SIZE && codigoToIndex[codigo] != -1) {
                    int index = codigoToIndex[codigo];
                    if (livros[index] != nullptr) {
                        livros[index]->mudaEstoque(acrescimo);
                        cout << "Estoque do produto alterado!" << endl;
                    } else if (alimenticios[index] != nullptr) {
                        alimenticios[index]->mudaEstoque(acrescimo);
                        cout << "Estoque do produto alterado!" << endl;
                    } else if (pecas[index] != nullptr) {
                        pecas[index]->mudaEstoque(acrescimo);
                        cout << "Estoque do produto alterado!" << endl;
                    } else {
                        cout << "Código de produto inválido!" << endl;
                    }
                } else {
                    cout << "Código de produto inválido!" << endl;
                }
                break;
            // Calcular valor total em estoque de um produto
            case 3:
                cout << "Digite o código do produto:" << endl;
                cin >> codigo;

                // Verificar se o código é válido
                if (codigo >= 0 && codigo < SIZE && codigoToIndex[codigo] != -1) {
                    int index = codigoToIndex[codigo];
                    double valorTotal;
                    if (livros[index] != nullptr) {
                        valorTotal = livros[index]->getQuantidade() * livros[index]->getPreco();
                    } else if (alimenticios[index] != nullptr) {
                        valorTotal = alimenticios[index]->getQuantidade() * alimenticios[index]->getPreco();
                    } else if (pecas[index] != nullptr) {
                        valorTotal = pecas[index]->getQuantidade() * pecas[index]->getPreco();
                    } else {
                        cout << "Código de produto inválido!" << endl;
                        break;
                    }
                    cout << "Valor total em estoque do produto: " << valorTotal << endl;
                } else {
                    cout << "Código de produto inválido!" << endl;
                }
                break;
            // Imprimir todos os produtos de um tipo
            case 4:
                cout << "Escolha o tipo de produto: " << endl;
                cout << "1. Livro" << endl;
                cout << "2. Alimentício" << endl;
                cout << "3. Peça de Carro" << endl;
                cout << "Opção: ";
                cin >> op;

                switch(op) {
                    case 1:
                        cout << "Produtos do tipo Livro:" << endl;
                        for (int i = 0; i < SIZE; ++i) {
                            if (livros[i] != nullptr) {
                                livros[i]->imprimeProduto();
                                cout << "Autor: " << livros[i]->getAutor() << endl;
                                cout << "Número de Páginas: " << livros[i]->getNumeroPaginas() << endl;
                                cout << endl;
                            }
                        }
                        break;
                    case 2:
                        cout << "Produtos do tipo Alimentício:" << endl;
                        for (int i = 0; i < SIZE; ++i) {
                            if (alimenticios[i] != nullptr) {
                                alimenticios[i]->imprimeProduto();
                                cout << "Validade: " << alimenticios[i]->getValidade() << endl;
                                cout << endl;
                            }
                        }
                        break;
                    case 3:
                        cout << "Produtos do tipo Peça de Carro:" << endl;
                        for (int i = 0; i < SIZE; ++i) {
                            if (pecas[i] != nullptr) {
                                pecas[i]->imprimeProduto();
                                cout << "Tipo de Carro: " << pecas[i]->getTipoCarro() << endl;
                                cout << "Marca: " << pecas[i]->getMarca() << endl;
                                cout << endl;
                            }
                        }
                        break;
                    default:
                        cout << "Opção inválida!" << endl;
                        break;
                }
                break;
            // Imprimir todos os produtos
            case 5:
                cout << "Todos os produtos cadastrados de todos os tipos:" << endl;
                cout << "Livros:" << endl;
                for (int i = 0; i < SIZE; ++i) {
                    if (livros[i] != nullptr) {
                        livros[i]->imprimeProduto();
                        cout << "Autor: " << livros[i]->getAutor() << endl;
                        cout << "Número de Páginas: " << livros[i]->getNumeroPaginas() << endl;
                        cout << endl;
                    }
                }
                cout << "Alimentos:" << endl;
                for (int i = 0; i < SIZE; ++i) {
                    if (alimenticios[i] != nullptr) {
                        alimenticios[i]->imprimeProduto();
                        cout << "Validade: " << alimenticios[i]->getValidade() << endl;
                        cout << endl;
                    }
                }
                cout << "Peças de Carro:" << endl;
                for (int i = 0; i < SIZE; ++i) {
                    if (pecas[i] != nullptr) {
                        pecas[i]->imprimeProduto();
                        cout << "Tipo de Carro: " << pecas[i]->getTipoCarro() << endl;
                        cout << "Marca: " << pecas[i]->getMarca() << endl;
                        cout << endl;
                    }
                }
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while (opcao != 0);

    // Libera memória alocada
    for (int i = 0; i < SIZE; ++i) {
        delete livros[i];
        delete alimenticios[i];
        delete pecas[i];
    }

    return 0;
}
