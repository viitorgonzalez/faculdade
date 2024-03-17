#include "Palavra.h"

Palavra::Palavra(string termo, int quantSignificado) {
    this->termo = termo;
    this->quantSignificado = quantSignificado;
    this->significado = new string[quantSignificado];
}

void Palavra::incluiSignificado(string significado) {
    this->significado[this->quantSignificado - 1] = significado;
    this->quantSignificado++;
}

void Palavra::alteraSignificado(string significado, int posicao) {
    this->significado[posicao] = significado;
}