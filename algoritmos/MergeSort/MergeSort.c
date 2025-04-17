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

/* Implementação do merge (auxiliar para mergesort) */
void merge(int *vet, int inicio, int meio, int fim, ull *trocas, ull *comparacoes)
{
    int *temp = alocaVetor(fim - inicio + 1);

    int i = inicio, j = meio + 1, idx = 0;
    if (!temp)
        return;

    while (i <= meio && j <= fim)
    {
        (*comparacoes)++;
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

    while (i <= meio)
    {
        temp[idx] = vet[i];
        idx++;
        i++;
    }

    while (j <= fim)
    {
        temp[idx] = vet[j];
        idx++;
        j++;
    }

    for (int k = inicio, y = 0; k <= fim; k++, y++)
        vet[k] = temp[y];
}

/*Implementação do MergeSort*/
void mergesort(int *vet, int inicio, int fim, ull *trocas, ull *comparacoes)
{
    if (inicio >= fim)
        return;

    int meio = (inicio + fim) / 2;

    mergesort(vet, inicio, meio, trocas, comparacoes);
    mergesort(vet, meio + 1, fim, trocas, comparacoes);
    merge(vet, inicio, meio, fim, trocas, comparacoes);
}

/*Wrap do MergeSort*/
ull *wrapMergeSort(int *vet, int tam)
{
    ull trocas = 0, comparacoes = 0;
    mergesort(vet, 0, tam - 1, &trocas, &comparacoes);

    ull *vetor = alocaVetorUll(2);

    if (!vetor)
        return NULL;

    vetor[0] = trocas;
    vetor[1] = comparacoes;

    return vetor;
}
