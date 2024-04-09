#include "Pais.cpp"

class Continente {
    public:
        string nome;
        Pais *vetor;

        Continente();

        void inserirPais(Pais pais); 
        void imprimirContinente(); 
        float densidade(); 
        float populacao(); 
        void maiorDimensao(); 
        void menorDimensao(); 
};
