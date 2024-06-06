#include "Nota.cpp" // ok
#include "Falta.cpp" // ok
#include "CadastroNota.cpp" // ok
#include "CadastroFalta.cpp" // 

int main() {
    Aluno a;
    Disciplina d;

    CadastroNota cn;
    CadastroFalta cf;

    // CadastroNota     OK
    cn.getTurmaNotas()[0].setN1(10);
    cout << cn.getTurmaNotas()[0].getN1() << endl;

    // CadastroFalta        testing
    cf.getTurmaFaltas()[0].getData() = 12;
    cout << cf.getTurmaFaltas()[0].getData();

    return 0;
}