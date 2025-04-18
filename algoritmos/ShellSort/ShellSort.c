/******************************************************************************
 * Arquivo: SelectionSort.c
 *
 * Descrição: Implementação do Shell Sort
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
#include "ShellSort.h"

/*Implementação do ShellSort*/
void shellsort(int *vet, int tam, ull *trocas, ull *comparacoes)
{
    for (int gap = tam / 2; gap > 0; gap = gap / 2)
    {
        for (int j = gap; j < tam; j++)
        {
            for (int k = j - gap; k >= 0; k -= gap)
            {
                (*comparacoes)++;
                if (vet[k + gap] >= vet[k])
                    break;
                else
                {
                    (*trocas)++;
                    swap(&vet[k + gap], &vet[k]);
                }
            }
        }
    }
};