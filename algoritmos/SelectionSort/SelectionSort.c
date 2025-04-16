/******************************************************************************
 * Arquivo: SelectionSort.c
 *
 * Descrição: Implementação do Selection Sort
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
#include "SelectionSort.h"

/*Implementação do Selection Sort*/
int *selectionsort(int *vet, int tam)
{
    int trocas, comparacoes;
    trocas = comparacoes = 0;

    if (!vet || tam == 0)
        return NULL;

    for (int i = 0; i < tam - 1; i++)
    {
        int menor = i;

        for (int j = i + 1; j < tam; j++)
        {
            comparacoes++;
            if (vet[j] < vet[menor])
                menor = j;
        }

        trocas++;
        int temp = vet[i];
        vet[i] = vet[menor];
        vet[menor] = temp;
    }

    int *vetor = alocaVetor(2);
    vetor[0] = trocas;
    vetor[1] = comparacoes;
    return vetor;
}
