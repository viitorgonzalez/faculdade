#include <stdio.h>
#include <stdlib.h>

int main() {
	int size = 0;
	float temporaryVariable = 0;
	
	printf("Quantos valores deseja armazenar no array?\n");
	scanf("%d", &size);

	if (size <= 0) {
        printf("Tamanho inválido.\n");
        return 1;
    }

	float *array = (float *)malloc(size * sizeof(float));
	if (array == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
	printf("\nForam alocados %d valores!\n", size);
	
	for(int i = 0; i < size; i++) {
		scanf("%f", &temporaryVariable);
		array[i] = temporaryVariable;
	}

	if(size < 10) {
		for(int i = 0; i < size; i++) {
			printf("%.2f\n", array[i]);
		}
	} else {
		for(int i = 0; i < 10; i++) {
			printf("%.2f\n", array[i]);
		}
	}
	
	free(array);

	return 0;
}

