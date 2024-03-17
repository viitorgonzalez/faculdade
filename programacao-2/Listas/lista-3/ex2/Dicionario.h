#ifndef DICIONARIO_H
#define DICIONARIO_H

#include <iostream>
#include "Palavra.h"

class Dicionario {
    public: 

        Palavra *palavras;
        int quantPalavra;

        Dicionario();

        void inserePalavra(Palavra palavra);
        void excluiPalavra(int posicao);
        void imprimePalavra();

};

#endif