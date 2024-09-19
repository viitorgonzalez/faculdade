#include "aluno.cpp"

class Disciplina: public Pessoa{
    private:
        string nome;
        Pessoa professor;
        int cargaHoraria;
    public:
        void imprimir(){
            cout<<nome<<endl;
            cout<<professor<<endl;
            cout<<cargaHoraria<<endl;
        }
        string getNome(){
            return nome;
        }
        void setNome(string nome){
            this->nome=nome;
        }
        Pessoa getProfessor(){
            return professor;
        }
        void setProfessor(Pessoa professor){
            this->professor=professor;
        }
        int getCargaHoraria(){
            return cargaHoraria;
        }
        void setCargaHoraria(int cargaHoraria){
            this->cargaHoraria=cargaHoraria;
        }
};