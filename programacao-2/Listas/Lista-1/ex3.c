#include <stdio.h>

void mimMax(int *array, int size, int *min, int *max) {
    *min = array[0], *max = array[0];

    for(int i = 1; i < size; i++) {
        if(*min > array[i])
            *min = array[i];
        if(*max < array[i])
            *max = array[i];
  }
    printf("Mínimo: %d", *min);
    printf("\nMáximo: %d", *max);
}

int main() {
    int arr[5] = {10, 20, 5, 30, 25}, size = 5;
    int min = 0, max = 0;

    mimMax(arr, size, &min, &max);

  return 0;
}
