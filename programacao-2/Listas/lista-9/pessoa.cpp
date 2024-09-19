#include <iostream>
#include <string.h>
using namespace std;

class Pessoa{
private:
    string nome;
    string cpf;
public:
    void Aluno(string nome, string cpf){
        this->nome=nome;
        this->cpf=cpf;
    }
    string getNome(){
        return nome;
    }
    void getNome(string nome){
        this->nome=nome;
    }
    string cpf(){
        return cpf;
    }
    void getCpf(string cpf){
        this->cpf=cpf;
    }
    

};

