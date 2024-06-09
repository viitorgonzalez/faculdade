#include "Aluno.cpp"
#include "Disciplina.cpp"

using namespace std;

class Falta {
    private:
        Aluno aluno;
        Disciplina disciplina;
        string *data;

    public:
        Falta() {
            data = new string[10];
        }

        Falta(Aluno aluno, Disciplina disciplina) {
            this->disciplina = disciplina;
            this->aluno = aluno;
            data = new string[10];
        }

        Aluno getAluno() {
            return aluno;
        }

        void setAluno(Aluno aluno) {
            this->aluno = aluno;
        }

        Disciplina getDisciplina() {
            return disciplina;
        }

        void setDisciplina(Disciplina disciplina) {
            this->disciplina = disciplina;
        }
        
        string *getData(){
            return data;
        }
        
        void setData(string *data){
            this->data = data;
        }
};
