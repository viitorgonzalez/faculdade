#include <iostream>
#include <string>

using namespace std;

class Pais {
    public:
        string sigla;
        string nome;
        int populacao;
        float dimensaoKmQuadrado;
        string *fronteiras;

        Pais();
        Pais(string sigla, string nome, int populacao, float dimensao);

        void imprimirPais(); 
        void verificaFronteira(string pais);
        float densidade(); 

};