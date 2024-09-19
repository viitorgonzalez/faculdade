#include <vector>
#include <string>
#include <stdexcept>
#include "disciplina.cpp"

class CadastroDisciplina {
private:
    std::vector<Disciplina> disciplinas;
public:
    void adicionarDisciplina(const Disciplina& disciplina) {
        disciplinas.push_back(disciplina);
    }

    Disciplina pesquisarDisciplina(const std::string& nome) const {
        for (const auto& disciplina : disciplinas) {
            if (disciplina.getNome() == nome) {
                return disciplina;
            }
        }
        throw std::runtime_error("Disciplina não encontrada");
    }

    std::vector<Disciplina> getDisciplinas() const { return disciplinas; }
    void setDisciplinas(const std::vector<Disciplina>& disciplinas) { this->disciplinas = disciplinas; }
};
