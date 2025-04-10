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
#include "../utils/utils.h"

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
void merge(int *vet, int inicio, int meio, int fim) {
    int *temp = alocaVetor(fim - inicio + 1);

    int i = inicio, j = meio + 1, idx = 0;
    if (!temp)
        return;

    while (i <= meio && j <= fim) {
        if (vet[i] <= vet[j]) {
            temp[idx] = vet[i];
            i++;
        } else {
            temp[idx] = vet[j];
            j++;
        }

        idx++;
    }

    while (i <= meio) {
        temp[idx] = vet[i];
        idx++;
        i++;
    }

    while (j <= fim) {
        temp[idx] = vet[j];
        idx++;
        j++;
    }

    for (int k = inicio, y = 0; k <= fim; k++, y++)
        vet[k] = temp[y];
}

/*Implementação do MergeSort*/
void mergesort(int *vet, int inicio, int fim, int *contador) {
    (*contador)++;
    if (inicio >= fim)
        return;

    int meio = (inicio + fim) / 2;

    mergesort(vet, inicio, meio, contador);
    mergesort(vet, meio + 1, fim, contador);
    merge(vet, inicio, meio, fim);
}

/*Wrap do MergeSort*/
void wrapMergeSort(int *vet, int tam) {
    int contador = 0;
    mergesort(vet, 0, tam-1, &contador);
}

/* Implementação do particiona (auxiliar para quicksort) */
int particiona(int *vet, int inicio, int fim) {
    int pivo = vet[inicio], pos = inicio, temp;

    for (int i = inicio + 1; i <= fim; i++) {
        if (vet[i] < pivo) {
            pos++;

            if (i != pos) {
                temp = vet[i];
                vet[i] = vet[pos];
                vet[pos] = temp;
            }
        }
    }

    temp = vet[inicio];
    vet[inicio] = vet[pos];
    vet[pos] = temp;

    return pos;
}

/*Implementação do QuickSort*/
void quicksort(int *vet, int inicio, int fim, int *contador) {
    (*contador)++;
    if (inicio < fim) {
        int posPivot = particiona(vet, inicio, fim);
        quicksort(vet, inicio, posPivot - 1, contador);
        quicksort(vet, posPivot + 1, fim, contador);
    }
}

/*Wrap do QuickSort*/
void wrapQuickSort(int *vet, int tam) {
    int contador = 0;
    quicksort(vet, 0, tam-1, &contador);
}
