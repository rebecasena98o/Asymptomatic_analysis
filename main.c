#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "HeapSort/heapsort.h"
//#include "QuickSort/quicksort.h"
#include "RadixSort/radixsort.h"


void gerarVetor(int arr[], int n){
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000000; 
    }
}

int main (){
    int tamanhos[] = {10, 25, 50, 75, 100, 250, 500, 750, 1000, 2500, 5000, 7500, 
                      10000, 25000, 50000, 75000, 100000, 250000, 500000, 750000, 1000000};
    int num_testes = sizeof(tamanhos) / sizeof(tamanhos[0]);
    int execucoes_por_tamanho = 5; 

    srand(time(NULL)); 

    printf("Tamanho | Tempo Médio (segundos)\n");
    printf("--------------------------------\n");

    for (int i = 0; i < num_testes; i++) {
        int n = tamanhos[i];
        double tempo_total = 0;

        for (int j = 0; j < execucoes_por_tamanho; j++) {
            
            int *vetor = (int *)malloc(n * sizeof(int));
            gerarVetor(vetor, n);

             
            clock_t inicio = clock();
            //heapSort(vetor, n); 
            //quickSort(vetor, 0, n - 1);
            radixSort(vetor, n);
            clock_t fim = clock();

            tempo_total += (double)(fim - inicio) / CLOCKS_PER_SEC;

            free(vetor); 
        }

        double media = tempo_total / execucoes_por_tamanho;
        printf("%7d | %f\n", n, media);
    }

    return 0;
}