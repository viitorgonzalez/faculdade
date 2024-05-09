#include <iostream>
#include "Conta.cpp"
#include "ContaBancaria.cpp"
#include "ContaCorrente.cpp"
#include "ContaCartaoCredito.cpp"
#include "ContaPoupanca.cpp"
#include "Data.cpp"

using namespace std;

const int MAX_CONTAS = 100;

int main() {
    ContaCorrente contasCorrente[MAX_CONTAS];
    ContaCartaoCredito contasCredito[MAX_CONTAS];
    ContaPoupanca contasPoupanca[MAX_CONTAS];

    int opcao;
    int numContasCorrente = 0;
    int numContasCredito = 0;
    int numContasPoupanca = 0;

    do {
        cout << "### Menu ###" << endl;
        cout << "1. Abrir conta" << endl;
        cout << "2. Sacar" << endl;
        cout << "3. Depositar" << endl;
        cout << "4. Imprimir Dados da Conta" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int tipoConta;
                cout << "### Abrir Conta ###" << endl;
                cout << "Escolha o tipo de conta:" << endl;
                cout << "1. Conta Corrente" << endl;
                cout << "2. Conta Cartão de Crédito" << endl;
                cout << "3. Conta Poupança" << endl;
                cout << "Opção: ";
                cin >> tipoConta;

                int numeroConta;
                cout << "Digite o número da conta: ";
                cin >> numeroConta;

                bool numeroExistente = false;
                for (int i = 0; i < numContasCorrente; ++i) {
                    if (contasCorrente[i].getNumero() == numeroConta) {
                        numeroExistente = true;
                        break;
                    }
                }
                for (int i = 0; i < numContasCredito; ++i) {
                    if (contasCredito[i].getNumero() == numeroConta) {
                        numeroExistente = true;
                        break;
                    }
                }
                for (int i = 0; i < numContasPoupanca; ++i) {
                    if (contasPoupanca[i].getNumero() == numeroConta) {
                        numeroExistente = true;
                        break;
                    }
                }

                if (numeroExistente) {
                    cout << "Número de conta já existente. Tente novamente." << endl;
                    break;
                }

                Data dataAbertura;
                int dia, mes, ano;
                cout << "Digite a data de abertura (dia mês ano): " << endl;
                cout << "Dia: ";
                cin >> dia;
                cout << "Mês: ";
                cin >> mes;
                cout << "Ano: ";
                cin >> ano;
                dataAbertura.setDia(dia);
                dataAbertura.setMes(mes);
                dataAbertura.setAno(ano);

                switch (tipoConta) {
                    case 1: {
                        ContaCorrente novaConta;
                        novaConta.setNumero(numeroConta);
                        novaConta.setDataAbertura(dataAbertura);
                        contasCorrente[numContasCorrente++] = novaConta;
                        cout << "Conta Corrente criada com sucesso!" << endl;
                        break;
                    }
                    case 2: {
                        ContaCartaoCredito novaConta;
                        novaConta.setNumero(numeroConta);
                        novaConta.setDataAbertura(dataAbertura);
                        contasCredito[numContasCredito++] = novaConta;
                        cout << "Conta Cartão de Crédito criada com sucesso!" << endl;
                        break;
                    }
                    case 3: {
                        ContaPoupanca novaConta;
                        novaConta.setNumero(numeroConta);
                        novaConta.setDataAbertura(dataAbertura);
                        contasPoupanca[numContasPoupanca++] = novaConta;
                        cout << "Conta Poupança criada com sucesso!" << endl;
                        break;
                    }
                    default:
                        cout << "Opção inválida." << endl;
                        break;
                }
                break;
            }
            case 2: {
                int numeroConta;
                float valorSaque;
                cout << "Digite o número da conta: ";
                cin >> numeroConta;

                bool encontrada = false;
                for (int i = 0; i < numContasCorrente; ++i) {
                    if (contasCorrente[i].getNumero() == numeroConta) {
                        encontrada = true;
                        cout << "Digite o valor do saque: ";
                        cin >> valorSaque;
                        contasCorrente[i].sacar(valorSaque);
                        break;
                    }
                }
                for (int i = 0; i < numContasCredito; ++i) {
                    if (contasCredito[i].getNumero() == numeroConta) {
                        encontrada = true;
                        cout << "Digite o valor do saque: ";
                        cin >> valorSaque;

                        if (contasCredito[i].getSaldo() - valorSaque < 0) {
                            cout << "Saldo insuficiente para realizar o saque." << endl;
                        } else {
                            contasCredito[i].setSaldo(contasCredito[i].getSaldo() - valorSaque);
                        }
                        break;
                    }
                }
                for (int i = 0; i < numContasPoupanca; ++i) {
                    if (contasPoupanca[i].getNumero() == numeroConta) {
                        encontrada = true;
                        cout << "Digite o valor do saque: ";
                        cin >> valorSaque;
                        contasPoupanca[i].sacar(valorSaque);
                        break;
                    }
                }

                if (!encontrada)
                    cout << "Conta não encontrada." << endl;

                break;
            }
            case 3: {
                int numeroConta;
                float valorDeposito;
                cout << "Digite o número da conta: ";
                cin >> numeroConta;

                bool encontrada = false;
                for (int i = 0; i < numContasCorrente; ++i) {
                    if (contasCorrente[i].getNumero() == numeroConta) {
                        encontrada = true;
                        cout << "Digite o valor do depósito: ";
                        cin >> valorDeposito;
                        contasCorrente[i].depositar(valorDeposito);
                        break;
                    }
                }
                for (int i = 0; i < numContasCredito; ++i) {
                    if (contasCredito[i].getNumero() == numeroConta) {
                        encontrada = true;
                        cout << "Digite o valor do depósito: ";
                        cin >> valorDeposito;

                        contasCredito[i].setSaldo(contasCredito[i].getSaldo() + valorDeposito);

                        break;
                    }
                }
                for (int i = 0; i < numContasPoupanca; ++i) {
                    if (contasPoupanca[i].getNumero() == numeroConta) {
                        encontrada = true;
                        cout << "Digite o valor do depósito: ";
                        cin >> valorDeposito;
                        contasPoupanca[i].depositar(valorDeposito);
                        break;
                    }
                }

                if (!encontrada)
                    cout << "Conta não encontrada." << endl;

                break;
            }
            case 4: {
                int numeroConta;
                cout << "Digite o número da conta: ";
                cin >> numeroConta;

                bool encontrada = false;
                for (int i = 0; i < numContasCorrente; ++i) {
                    if (contasCorrente[i].getNumero() == numeroConta) {
                        contasCorrente[i].imprimirConta();
                        encontrada = true;
                        break;
                    }
                }
                for (int i = 0; i < numContasCredito; ++i) {
                    if (contasCredito[i].getNumero() == numeroConta) {
                        contasCredito[i].imprimirConta();
                        encontrada = true;
                        break;
                    }
                }
                for (int i = 0; i < numContasPoupanca; ++i) {
                    if (contasPoupanca[i].getNumero() == numeroConta) {
                        contasPoupanca[i].imprimirConta();
                        encontrada = true;
                        break;
                    }
                }

                if (!encontrada)
                    cout << "Conta não encontrada." << endl;

                break;
            }
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
        
    } while (opcao != 0);

    return 0;
}
