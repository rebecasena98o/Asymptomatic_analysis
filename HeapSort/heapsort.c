#include "heapsort.h"

void heapify(int arr[], int n, int i){
    int largest = i;
    int esquerda = 2 * i + 1; // left
    int direita = 2 * i + 2; // right

    if(esquerda < n && arr[esquerda] > arr[largest])
        largest = esquerda;

    if(direita < n && arr[direita] > arr[largest])
        largest = direita;
    
    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}