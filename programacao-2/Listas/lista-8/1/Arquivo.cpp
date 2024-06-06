#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Arquivo {
    public:
        void escrever(string nomeDoArquivo, string conteudo) {
            ofstream arquivo;
            arquivo.open(nomeDoArquivo.c_str(), ios::out);
            if (!arquivo)
                cout << "Impossivel abrir arquivo!" << endl;
            arquivo << conteudo << "\n";
            arquivo.close();
        }

        string ler(string nomeDoArquivo) {
            ifstream arquivo;
            arquivo.open(nomeDoArquivo.c_str(), ios::in);
            string linha = "", retorno = "";
            while (!arquivo.eof()) {
                getline(arquivo, linha);
                retorno += linha;
            }
            arquivo.close();
            return retorno;
        }

        int quantidadeLetra(string nomeDoArquivo, char letra) {
            string conteudo = ler(nomeDoArquivo);
            int quant = 0;
            for (int i = 0; i < conteudo.length(); i++) {
                if (conteudo[i] == letra)
                    quant++;
            }
            return quant;
        }

        int quantidadePalavra(string nomeDoArquivo, string palavra) {
            vector<string> palavras;
            ifstream arquivo(nomeDoArquivo.c_str());
            string linha, palavraArquivo, palavraAtual;

            while (arquivo >> linha) {
                palavraAtual = "";
                for (string::iterator it = linha.begin(); it != linha.end(); ++it) {
                    if (*it == ' ') {
                        if (!palavraAtual.empty()) {
                            palavras.push_back(palavraAtual);
                            palavraAtual = "";
                        }
                    } else {
                        palavraAtual += *it;
                    }
                }
                if (!palavraAtual.empty())
                    palavras.push_back(palavraAtual);
            }

            int quant = 0;
            for (vector<string>::iterator it = palavras.begin(); it != palavras.end(); ++it) {
                if (*it == palavra)
                    quant++;
            }
            return quant;
        }
};
