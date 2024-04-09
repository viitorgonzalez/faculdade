e#include <stdio.h>

void copiaString(char *origem, char *destino) {

    while (*origem != '\0') {
        *destino = *origem;
        destino++;
        origem++;
    }

    *destino = '\0';

}

int main() {
    char origem[] = "Minha String";
    char destino[50];

    copiaString(origem, destino);

    printf("String de origem: %s\nString de destino: %s\n", origem, destino);

    return 0;
}
