# Projeto Análise Assintótica - Atividade Prática

Este repositório contém a implementação e análise de tempo de diferentes algoritmos de ordenação em C.

## 📂 Estrutura do Projeto

* **HeapSort/**: Implementação do algoritmo HeapSort.
* **QuickSort/**: Implementação do algoritmo QuickSort.
* **RadixSort/**: Implementação do algoritmo RadixSort.
* **main.c**: Arquivo principal para testes e medição de desempenho.

## 🚀 Como Compilar e Rodar

Para compilar o projeto usando o arquivo principal é necessário escolher qual algoritmo a ser compilado, por exemplo:

```bash
na main:
#include "RadixSort/radixsort.h" - sem comentário - linha 6
radixSort(vetor, n); - sem comentário - linha 39
gcc  RadixSort/radixsort.c main.c -o programa_teste_Radix
```

Para executar:
```bash
./programa_teste_Radix
```

