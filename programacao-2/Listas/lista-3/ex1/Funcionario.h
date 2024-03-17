#include <iostream>
#include <string>

using namespace std;

class Funcionario {

    public:
        string cpf;
        string nome;
        double salario;

        Funcionario();
        Funcionario(string cpf, string nome, double salario);

        void atualizaSalario(double comissaoVenda);
        void retornaFuncionario();

};