#include "Aluno.cpp"
#include "Disciplina.cpp"

using namespace std;

class Nota {
    private:
        Aluno aluno;
        Disciplina disciplina;
        float n1;
        float n2;
        float n3;

    public:
        Nota() {}

        Nota(Aluno aluno, Disciplina disciplina) {
            this->aluno = aluno;
            this->disciplina = disciplina;
            n1 = 0;
            n2 = 0;
            n3 = 0;
        }

        Aluno getAluno() {
            return aluno;
        }

        Disciplina getDisciplina() {
            return disciplina;
        }

        float getN1() {
            return n1;
        }

        float getN2() {
            return n2;
        }

        float getN3() {
            return n3;
        }

        void setAluno(Aluno aluno) {
            this->aluno = aluno;
        }

        void setDisciplina(Disciplina disciplina) {
            this->disciplina = disciplina;
        }

        void setN1(float n1) {
            this->n1 = n1;
        }

        void setN2(float n2) {
            this->n2 = n2;
        }

        void setN3(float n3) {
            this->n3 = n3;
        }

        void exibirNota() {
            cout << "Aluno: " << aluno.getNome() << endl;
            cout << "Disciplina: " << disciplina.getMateria() << endl;
            cout << "Nota 1: " << n1 << endl;
            cout << "Nota 2: " << n2 << endl;
            cout << "Nota 3: " << n3 << endl;
        }
};
