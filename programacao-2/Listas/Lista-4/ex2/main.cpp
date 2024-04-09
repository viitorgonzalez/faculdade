#include "Vaga.cpp"

int main() {
    Vaga vagas[10];

    int opcao;
    int indice = 0;
    float total = 0;
    int horaSaida;
    string data;

    do {
        cout << "Menu de Opções:" << endl;
        cout << "1. Cadastrar vaga" << endl;
        cout << "2. Calcular Valor Total" << endl;
        cout << "3. Imprimir Vaga" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (indice < 10) {
                    {
                        string modelo, placa, nome, cpf, endereco;
                        int ano;
                        
                        cout << "Informe o modelo do carro: ";
                        cin >> modelo;
                        cout << "Informe a placa do carro: ";
                        cin >> placa;
                        cout << "Informe o ano do carro: ";
                        cin >> ano;
                        cout << "Informe o nome do proprietário: ";
                        cin >> nome;
                        cout << "Informe o CPF do proprietário: ";
                        cin >> cpf;
                        cout << "Informe o endereço do proprietário: ";
                        cin >> endereco;
                        cout << "Informe a data: "; 
                        cin >> data;

                        Carro* novoCarro = new Carro();
                        novoCarro->modelo = modelo;
                        novoCarro->placa = placa;
                        novoCarro->ano = ano;

                        Proprietario* novoProprietario = new Proprietario(nome, cpf, endereco);
                        vagas[indice].carro = novoCarro;
                        vagas[indice].carro->dono = novoProprietario;
                        vagas[indice].data = data;
                    }

                    cout << "Informe a hora de entrada: ";
                    cin >> vagas[indice].horaChegada;
                    cout << "Informe a hora de saída: ";
                    cin >> vagas[indice].horaSaida;
                    indice++;
                    cout << "Entrada cadastrada com sucesso!" << endl;
                } else {
                    cout << "Limite máximo de vagas atingido!" << endl;
                }
                break;

            case 2:
                total = 0;
                for (int i = 0; i < indice; i++) {
                    total += vagas[i].calculaValorTotal();
                }
                cout << "Valor total: R$" << total << endl;
                break;

            case 3:
                for (int i = 0; i < indice; i++) {
                    cout << "Vaga " << i + 1 << ":" << endl;
                    vagas[i].imprimirVaga();
                }
                break;
            
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}
