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
    int gap, i, j, temp;

    for (gap = tam / 2; gap >= 1; gap /= 2)
    {
        for (i = gap; i < tam; i++)
        {
            temp = vet[i];
            j = i - gap;
            while (j >= 0 && vet[j] > temp)
            {
                vet[j + gap] = vet[j];
                j = j - gap;
            }
            vet[j + gap] = temp;
        }
    }
};