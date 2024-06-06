#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Arquivo {
    private:
        string nomeDoArquivo;

    public:
        Arquivo(string nome) : nomeArquivo(nome) {}

        void lerConteudo() {
            ifstream arquivo(nomeDoArquivo.c_str());
            string produto;
            double preco, total = 0.0;

            if (arquivo.is_open()) {
                cout << "Lista de produtos:" << endl;
                while (arquivo >> produto >> preco) {
                    cout << produto << " - R$ " << preco << endl;
                    total += preco;
                }
                arquivo.close();
                cout << "Valor total da compra: R$ " << total << endl;
            } else {
                cout << "Erro ao abrir o arquivo." << endl;
            }
        }
};
