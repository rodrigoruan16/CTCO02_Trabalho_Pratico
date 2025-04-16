/******************************************************************************
 * Arquivo: QuickSort.c
 *
 * Descrição: Implementação do Quick Sort
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
#include "QuickSort.h"

/* Implementação do particiona (auxiliar para quicksort) */
int particiona(int *vet, int inicio, int fim, int *trocas, int *comparacoes)
{
    int pivo = vet[inicio], pos = inicio, temp;

    for (int i = inicio + 1; i <= fim; i++)
    {
        (*comparacoes)++;
        if (vet[i] < pivo)
        {
            pos++;

            if (i != pos)
            {
                (*trocas)++;
                temp = vet[i];
                vet[i] = vet[pos];
                vet[pos] = temp;
            }
        }
    }

    (*trocas)++;
    temp = vet[inicio];
    vet[inicio] = vet[pos];
    vet[pos] = temp;

    return pos;
}

/*Implementação do QuickSort*/
void quicksort(int *vet, int inicio, int fim, int *trocas, int *comparacoes)
{
    if (inicio < fim)
    {
        int posPivot = particiona(vet, inicio, fim, trocas, comparacoes);
        quicksort(vet, inicio, posPivot - 1, trocas, comparacoes);
        quicksort(vet, posPivot + 1, fim, trocas, comparacoes);
    }
}

/*Wrap do QuickSort*/
int *wrapQuickSort(int *vet, int tam)
{
    int trocas, comparacoes;
    trocas = comparacoes = 0;
    quicksort(vet, 0, tam - 1, &trocas, &comparacoes);
    int *vetor = alocaVetor(2);
    vetor[0] = trocas;
    vetor[1] = comparacoes;
    return vetor;
}
