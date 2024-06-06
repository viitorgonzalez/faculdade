#pragma once

#include "Falta.cpp"

class CadastroFalta {
private:
    Falta *turmaFaltas;

public:
    CadastroFalta() {
        turmaFaltas = new Falta[10];
    }

    Falta *getTurmaFaltas() {
        return turmaFaltas;
    }

    void setTurmaFaltas(Falta *turmaFaltas) {
        this->turmaFaltas = turmaFaltas;
    }

};