/******************************************************************************
 * Arquivo: InsertionSort.c
 *
 * Descrição: Implementação do Merge Sort e auxiliares
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
#include "../../utils/utils.h"
#include "MergeSort.h"

/**
* Função de merge para o algoritmo MergeSort
* Combina duas sub-listas ordenadas em uma única lista ordenada
*/
void merge(int* vet, int inicio, int meio, int fim, ull* trocas, ull* comparacoes)
{
    int* temp = alocaVetor(fim - inicio + 1);

    int i = inicio, j = meio + 1, idx = 0;
    if (!temp)
        return;

    while (i <= meio && j <= fim)
    {
        (*comparacoes)++;
        /* Seleciona o menor elemento entre as duas sub-listas */
        if (vet[i] <= vet[j])
        {
            temp[idx] = vet[i];
            i++;
        }
        else
        {
            temp[idx] = vet[j];
            j++;
        }

        idx++;
    }

    /* Copia os elementos restantes da primeira sub-lista, se houver */
    while (i <= meio)
    {
        temp[idx] = vet[i];
        idx++;
        i++;
    }

    /* Copia os elementos restantes da segunda sub-lista, se houver */
    while (j <= fim)
    {
        temp[idx] = vet[j];
        idx++;
        j++;
    }

    /* Copia os elementos para o vetor original */
    for (int k = inicio, y = 0; k <= fim; k++, y++)
        vet[k] = temp[y];
    
    free(temp);
}

/*Implementação do MergeSort*/
void mergesort(int* vet, int inicio, int fim, ull* trocas, ull* comparacoes)
{
    if (inicio >= fim)
        return;

    int meio = (inicio + fim) / 2;

    mergesort(vet, inicio, meio, trocas, comparacoes);
    mergesort(vet, meio + 1, fim, trocas, comparacoes);
    merge(vet, inicio, meio, fim, trocas, comparacoes);
}

/*Wrap do MergeSort*/
void wrapMergeSort(int* vet, int tam, ull* trocas, ull* comparacoes)
{
    mergesort(vet, 0, tam - 1, trocas, comparacoes);
}
