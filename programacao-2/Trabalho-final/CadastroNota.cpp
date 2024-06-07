#pragma once

#include "Nota.cpp"

class CadastroNota {
private:
    Nota *turmaNotas;

public:
    CadastroNota() {
        turmaNotas = new Nota[10];
    }

    Nota *getTurmaNotas() {
        return turmaNotas;
    }

    void setTurmaNotas(Nota *turmaNotas) {
        this->turmaNotas = turmaNotas;
    }
};