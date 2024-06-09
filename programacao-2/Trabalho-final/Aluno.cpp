#pragma once

#include "Pessoa.cpp"

class Aluno : public Pessoa { 
    private:
        int matricula;

    public:
        Aluno() : Pessoa("") {
            matricula = 0;
        }

        Aluno(string nome, int matricula) : Pessoa(nome) {
            this-> matricula = matricula;
        }

        void setMatricula(int novaMatricula) {
            matricula = novaMatricula;
        }

        int getMatricula() {
            return matricula;
        }
};
