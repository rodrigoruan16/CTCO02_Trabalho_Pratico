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
#include "QuickSort.h"

/* Implementação do particiona (auxiliar para quicksort) */
int particiona(int *vet, int inicio, int fim)
{
    int pivo = vet[inicio], pos = inicio, temp;

    for (int i = inicio + 1; i <= fim; i++)
    {
        if (vet[i] < pivo)
        {
            pos++;

            if (i != pos)
            {
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
void quicksort(int *vet, int inicio, int fim)
{
    if (inicio < fim)
    {
        int posPivot = particiona(vet, inicio, fim);
        quicksort(vet, inicio, posPivot - 1);
        quicksort(vet, posPivot + 1, fim);
    }
}

/*Wrap do QuickSort*/
void wrapQuickSort(int *vet, int tam)
{
    int contador = 0;
    quicksort(vet, 0, tam - 1);
}
