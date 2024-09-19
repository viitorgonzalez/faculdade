#include <iostream>
#include <vector>
#include "pessoa.cpp"
#include "aluno.cpp"
#include "disciplina.cpp"
#include "cadastroAluno.cpp"
#include "CadastroDisciplina.cpp"
#include "matricula.cpp"

int main() {
    CadastroAluno cadastroAluno;
    CadastroDisciplina cadastroDisciplina;
    std::vector<Matricula> matriculas;
    int numMatriculas;

    std::cout << "Informe o número de matrículas: ";
    std::cin >> numMatriculas;

    for (int i = 0; i < numMatriculas; ++i) {
        std::string nome, cpf, curso, endereco, nomeDisciplina, nomeProfessor;
        int numMatricula, semestre, cargaHoraria;

        std::cout << "Cadastro de Aluno" << std::endl;
        std::cout << "Nome: ";
        std::cin >> nome;
        std::cout << "CPF: ";
        std::cin >> cpf;
        std::cout << "Num Matricula: ";
        std::cin >> numMatricula;
        std::cout << "Semestre: ";
        std::cin >> semestre;
        std::cout << "Curso: ";
        std::cin >> curso;
        std::cout << "Endereco: ";
        std::cin >> endereco;

        Aluno aluno(nome, cpf, numMatricula, semestre, curso, endereco);
        cadastroAluno.adicionarAluno(aluno);

        std::cout << "Cadastro de Disciplina" << std::endl;
        std::cout << "Nome da Disciplina: ";
        std::cin >> nomeDisciplina;
        std::cout << "Nome do Professor: ";
        std::cin >> nomeProfessor;
        std::cout << "Carga Horaria: ";
        std::cin >> cargaHoraria;

        Pessoa professor(nomeProfessor, "12345678900");
        Disciplina disciplina(nomeDisciplina, professor, cargaHoraria);
        cadastroDisciplina.adicionarDisciplina(disciplina);

        Matricula matricula(aluno, semestre);
        matricula.adicionarDisciplina(disciplina);
        matriculas.push_back(matricula);
    }

    std::cout << "Impressão das Matrículas:" << std::endl;
    for (const auto& matricula : matriculas) {
        matricula.imprimir();
    }

    return 0;
}
