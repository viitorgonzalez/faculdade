#include <vector>
#include <string>
#include <stdexcept>
#include "Aluno.cpp"

class CadastroAluno {
private:
    std::vector<Aluno> alunos;
public:
    void adicionarAluno(const Aluno& aluno) {
        alunos.push_back(aluno);
    }

    Aluno pesquisarAluno(const std::string& nome) const {
        for (const auto& aluno : alunos) {
            if (aluno.getNome() == nome) {
                return aluno;
            }
        }
        throw std::runtime_error("Aluno não encontrado");
    }

    std::vector<Aluno> getAlunos() const { return alunos; }
    void setAlunos(const std::vector<Aluno>& alunos) { this->alunos = alunos; }
};
