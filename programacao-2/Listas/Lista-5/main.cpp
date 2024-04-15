#include "Venda.cpp"

int main() {
    int quant = 0, opcao = 0, controle = 0;
    cout << "Quantidade de vendas: " << endl;
    cin >> quant;
    
    Venda *v = new Venda[quant];

    do {
        cout << "1 - Cadastrar Venda\n2 - Imprimir 1 Venda\n3 - Imprimir todas Vendas\n4 - Media de todas Vendas\n0 - Sair" << endl;
        cin >> opcao;
        cin.ignore(); 

        switch(opcao) {
            case 1: {
                Venda p;
                float total = 0;
                cout << "Cliente: " << endl;
                string cliente;
                getline(cin, cliente);
                p.setCliente(cliente);
                cout << "Data: " << endl;
                string data;
                getline(cin, data);
                p.setData(data);
                for(int i = 0; i < 10; i++) {
                    string descricao;
                    float preco;
                    int quantidade;
                    float valorTotal;
                    cout << "Descricao: " << endl;
                    getline(cin, descricao);
                    p.getItens()[i].getProduto().setPreco(preco);
                    cout << "Preco: " << endl;
                    cin >> preco;
                    p.getItens()[i].getProduto().setPreco(preco);
                    cout << "Quantidade: " << endl;
                    cin >> quantidade;
                    p.getItens()[i].setQuantidade(quantidade);
                    valorTotal = preco * quantidade;
                    p.getItens()[i].setValorTotal(valorTotal);
                    total += valorTotal;
                    cin.ignore(); 
                }
                p.setValorTotalVenda(total);
                v[controle] = p;
                controle++;
                break;
            }
            case 2: {
                int posicao = 0;
                cout << "Digite o numero da venda: " << endl;
                cin >> posicao;
                v[posicao].imprimirVenda();
                break;
            }
            case 3: {
                for(int i = 0; i < controle; i++) {
                    v[i].imprimirVenda();
                }
                break;
            }
            case 4: {
                float soma = 0; 
                for (int i = 0; i < controle; i++) {
                    soma += v[i].getValorTotalVenda();
                }
                float media = soma / controle;
                cout << "R$ " << media << endl;
                break;
            }
        }   
    } while(opcao != 0);

    delete[] v; 
    return 0;
};



