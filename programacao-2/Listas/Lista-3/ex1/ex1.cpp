#include "Funcionario.cpp"

int main() {
    Funcionario funcionario;
    double comissaoVenda = 0;

    cout << "Digite o cpf: " << endl;
    getline(cin, funcionario.cpf);

    cout << "Digite o nome: " << endl;
    getline(cin, funcionario.nome);

    cout << "Digite o salario: " << endl;
    cin >> funcionario.salario;

    cout << "Digite a comissão: " << endl;
    cin >> comissaoVenda;

    funcionario.atualizaSalario(comissaoVenda);
    funcionario.retornaFuncionario();

    return 0;
}
