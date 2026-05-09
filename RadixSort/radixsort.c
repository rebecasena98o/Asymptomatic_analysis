#include "radixsort.h"
#include <stdlib.h>

int obterMaior(int arr[], int n) {
    int maior = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maior)
            maior = arr[i];
    return maior;
}

void countingSortParaRadix(int arr[], int n, int exp) {
    int *saida = (int *)malloc(n * sizeof(int));
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (i = n - 1; i >= 0; i--) {
        saida[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (i = 0; i < n; i++)
        arr[i] = saida[i];
    
    free(saida);
}

void radixSort(int arr[], int n) {
    int m = obterMaior(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSortParaRadix(arr, n, exp);
}