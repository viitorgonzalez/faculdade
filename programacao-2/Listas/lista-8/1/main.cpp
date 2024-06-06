#include "Arquivo.cpp"

int main() {
    Arquivo arquivo;
    string nomeArquivo, conteudo, palavra;
    char letra;
    int opcao;

    do {
        cout << "-------------- Menu: --------------\n";
        cout << "1. Escrever no arquivo\n";
        cout << "2. Imprimir conteudo do arquivo\n";
        cout << "3. Quantidade de determinada letra\n";
        cout << "4. Quantidade de determinada palavra\n";
        cout << "5. Sair\n";
        cout << "-----------------------------------\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o nome do arquivo: ";
                cin >> nomeArquivo;
                cout << "Digite o conteudo: ";
                cin.ignore();
                getline(cin, conteudo);
                arquivo.escrever(nomeArquivo, conteudo);
                cout << "Conteudo escrito no arquivo com sucesso.\n";
                break;
            case 2:
                cout << "Digite o nome do arquivo: ";
                cin >> nomeArquivo;
                cout << "Conteudo do arquivo:\n";
                cout << arquivo.ler(nomeArquivo) << endl;
                break;
            case 3:
                cout << "Digite o nome do arquivo: ";
                cin >> nomeArquivo;
                cout << "Digite a letra: ";
                cin >> letra;
                cout << "Quantidade da letra '" << letra << "' no arquivo: ";
                cout << arquivo.quantidadeLetra(nomeArquivo, letra) << endl;
                break;
            case 4:
                cout << "Digite o nome do arquivo: ";
                cin >> nomeArquivo;
                cout << "Digite a palavra: ";
                cin >> palavra;
                cout << "Quantidade da palavra '" << palavra << "' no arquivo: ";
                cout << arquivo.quantidadePalavra(nomeArquivo, palavra) << endl;
                break;
            case 5:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }
    } while (opcao != 5);

    return 0;
}
