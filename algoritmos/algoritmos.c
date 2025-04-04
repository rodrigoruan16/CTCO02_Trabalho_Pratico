/******************************************************************************
 * Arquivo: algoritmos.c
 * 
 * Descrição: Implementação dos algoritmo de ordenação.
 *            Este arquivo contém a funções de sort.
 * 
 * Criadores: 
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - LUCAS ALEXANDRE DOS SANTOS BAESSO - 2024007172
 *            - RAFAEL FERNANDO AURELIO RIBEIRO - 2024009426
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 * 
 * Data: 04/04/2025
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "utils/utils.h"

/*Implementação do InsertionSort*/
void insertionsort(int *vet, int tam) {
    if (!vet || tam == 0)
        return;

    for (int i = 1; i < tam; i++) {
        int marcador = i - 1, elemento = vet[i];

        while (marcador >= 0 && vet[marcador] > elemento) {
            vet[marcador + 1] = vet[marcador];
            marcador--;
        }

        vet[marcador + 1] = elemento;
    }
}

/*Implementação do SelectionSort*/
void selectionsort(int *vet, int tam) {
    if (!vet || tam == 0)
        return;

    for (int i = 0; i < tam - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[menor])
                menor = j;
        }

        int temp = vet[i];
        vet[i] = vet[menor];
        vet[menor] = temp;
    }
}

/* Implementação do merge (auxiliar para mergesort) */
void merge(int *vet, int low, int mid, int high) {
    int *temp = alocaVetor(high - low + 1);
    if (!temp)
        return NULL;

    int left = low, right = mid + 1, idx = 0;

    while (left <= mid && right <= high) {
        if (vet[left] <= vet[right]) {
            temp[idx] = vet[left];
            left++;
        } else {
            temp[idx] = vet[right];
            right++;
        }

        idx++;
    }

    while (left <= mid) {
        temp[idx] = vet[left];
        left++;
        idx++;
    }

    while (right <= high) {
        temp[idx] = vet[right];
        right++;
        idx++;
    }

    for (int i = low; i <= high; i++) {
        vet[i] = vet[i - low];
    }
}

/*Implementação do MergeSort*/
void mergesort(int *vet, int low, int high) {
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergesort(vet, low, mid);
    mergesort(vet, mid + 1, high);
    merge(vet, low, mid, high);
}

/*Wrap do MergeSort*/
void wrapMergeSort(int *vet, int tam) {
    mergesort(vet, 0, tam-1);
}

/*Implementação do QuickSort*/
void quicksort(int *vet, int tam);
