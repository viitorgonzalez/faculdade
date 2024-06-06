#pragma once

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    protected:
        string nome;

    public:
        Pessoa(string nome) {
            this->nome = nome;
        }

        string getNome() {
            return nome;
        }

        void setNome(string novoNome) {
            nome = novoNome;
        }
};
