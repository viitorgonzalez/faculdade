#include <stdio.h>

void trocaValores(int *a, int *b) {
    int aux = *b;
    *b = *a;
    *a = aux;
}

int main() {
    int a = 6, b = 8;

    trocaValores(&a, &b);

    printf("Resultado: a = %d, b = %d\n", a, b);

    return 0;
}
