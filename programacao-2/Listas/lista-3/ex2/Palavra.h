#ifndef PALAVRA_H
#define PALAVRA_H

#include <iostream>
#include <string.h>

using namespace std;

class Palavra {
    public:

        string termo;
        int quantSignificado;
        string *significado;

        Palavra(string termo, int quantSignificado);

        void incluiSignificado(string significado);
        void alteraSignificado(string significado, int posicao);

};

#endif