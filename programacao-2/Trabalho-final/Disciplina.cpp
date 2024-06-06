#pragma once

class Disciplina {
    private:
        string materia;
        string curso;

    public:
        Disciplina() {
            materia =  "";
            curso =  "";
        }

        Disciplina(string materia, string curso) {
            this->materia = materia;
            this->curso = curso;
        }

        string getMateria() {
            return materia;
        }

        string getCurso() {
            return curso;
        }

        void setMateria(string novaMateria) {
            materia = novaMateria;
        }

        void setCurso(string novoCurso) {
            curso = novoCurso;
        }

        void exibirDisciplina() {
            cout << "Matéria: " << materia << endl;
            cout << "Curso: " << curso << endl;
        }
};