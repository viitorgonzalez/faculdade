#include <stdio.h>

int somaArr(int arr[], int tam) {
    return (tam == 0) ? 0 : arr[tam - 1] + somaArr(arr, tam - 1) ;
}

int main() {
    int arr[] = {1, 2, 3 , 4, 5, 6, 7};
    int tam = sizeof(arr) / sizeof(arr[0]);

    printf("Soma: %d", somaArr(arr, tam));

    return 0;
}
