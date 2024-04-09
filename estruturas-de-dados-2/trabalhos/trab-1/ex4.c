#include <stdio.h>

void trocaValores(int *a, int *b) {
    int aux = *b;
    *b = *a;
    *a = aux;
}

int main() {
    int a = 6, b = 8;

    trocaValores();

    printf("Valores:\n");

    return 0;
}
