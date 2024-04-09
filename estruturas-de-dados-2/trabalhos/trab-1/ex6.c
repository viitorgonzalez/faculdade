#include <stdio.h>

int fatorial(int n) {
    return (n == 0) ? 1 : n * fatorial(n - 1);
}

int main() {
    int n = 5;

    printf("Resultado: %d", fatorial(n));

    return 0;
}
