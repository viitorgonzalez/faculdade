#include <vector>
#include <iostream>
#include "aluno.cpp"
#include "disciplina.cpp"

class Matricula {
private:
    Aluno aluno;
    int semestre;
    std::vector<Disciplina> disciplinas;
public:
    Matricula(const Aluno& aluno, int semestre) : aluno(aluno), semestre(semestre) {}

    Aluno getAluno() const { return aluno; }
    void setAluno(const Aluno& aluno) { this->aluno = aluno; }

    int getSemestre() const { return semestre; }
    void setSemestre(int semestre) { this->semestre = semestre; }

    std::vector<Disciplina> getDisciplinas() const { return disciplinas; }
    void setDisciplinas(const std::vector<Disciplina>& disciplinas) { this->disciplinas = disciplinas; }

    void adicionarDisciplina(const Disciplina& disciplina) {
        disciplinas.push_back(disciplina);
    }

    void imprimir() const {
        std::cout << "Aluno: " << aluno.getNome() << "\n"
                  << "Semestre: " << semestre << "\n";
        for (const auto& disciplina : disciplinas) {
            disciplina.imprimir();
        }
    }
};
