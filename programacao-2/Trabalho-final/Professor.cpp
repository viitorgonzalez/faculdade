#pragma once

#include "Pessoa.cpp"

class Professor : public Pessoa {
private:
    int id;

public:
    Professor(const string nome, int id) : Pessoa(nome), id(id) {}

    void setId(int novoId) {
        id = novoId;
    }

    int getId() const {
        return id;
    }
};