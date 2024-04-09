#include <iostream>
#include <string>

using namespace std;

class Proprietario {

    public:
        string nome;
        string cpf;
        string endereco;

        Proprietario();
        Proprietario(string nome, string cpf, string endereco);

        void imprimirProprietario();

};
