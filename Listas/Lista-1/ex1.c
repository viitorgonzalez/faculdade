#include <stdio.h>

const int ARRAY_SIZE = 15;

int funcMaior(int *array) {
	int bigger = array[0];
	
	for(int i = 1; i < ARRAY_SIZE; i++) {
		if(bigger < array[i]) {
			bigger = array[i];
		}
	}
	return bigger;
}

int funcMenor(int *array) {
	int smaller = array[0];
	
	for(int i = 1; i < ARRAY_SIZE; i++) {
		if(smaller > array[i]) {
			smaller = array[i];
		}
	}
	return smaller;
}

float funcMedia(int *array) {
	float average = 0;
	
	for(int i = 0; i < ARRAY_SIZE; i++) {
		average += array[i];
	}
	return (average /= ARRAY_SIZE);
}

int main() {
	int array[ARRAY_SIZE], temporaryVariable = 0;
	
	for(int i = 0; i < ARRAY_SIZE; i++) {
		scanf("%d", &temporaryVariable);
		array[i] = temporaryVariable;
	}
	
	printf("Maior: %d", funcMaior(array));
	printf("\nMenor: %d", funcMenor(array));
	printf("\nMédia: %.2f", funcMedia(array));
	
	return 0;
}

