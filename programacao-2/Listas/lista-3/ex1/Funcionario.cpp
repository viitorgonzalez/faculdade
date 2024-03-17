#include "Funcionario.h"

Funcionario::Funcionario() {
    this->cpf = "";
    this->nome = "";
    this->salario = 0;
}

Funcionario::Funcionario(string cpf, string nome, double salario) {
    this->cpf = cpf;
    this->nome = nome;
    this->salario = salario;
}

void Funcionario::atualizaSalario(double comissaoVenda) {
    this->salario += (comissaoVenda * 0.018);
}

void Funcionario::retornaFuncionario() {
    cout << "O vendedor " << this->nome << " com o número de cpf " << this->cpf << " recebeu este mês a quantia de " << this->salario << " reais." << endl;
}