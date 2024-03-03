#include <stdio.h>

int main() {
    int entry = 0, counter = 0, sum = 0;

    do {
        printf("\nDigite um número: ");
        scanf("%d", &entry);

        sum += entry;
        counter++;

        } while(entry != 0);

    printf("\nSomatório: %d", sum);
    printf("\nQuantidade de números: %d", (counter - 1));

    return 0;
}
