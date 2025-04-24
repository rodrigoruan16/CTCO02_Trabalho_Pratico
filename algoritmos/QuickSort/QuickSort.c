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

/**
* Função de particionamento para o algoritmo QuickSort
* Esta função seleciona o último elemento como pivô e rearranja o vetor
* de forma que elementos menores que o pivô fiquem à esquerda e maiores à direita
*/
int particiona(int *vet, int inicio, int fim, ull *trocas, ull *comparacoes)
{
    int pivo = vet[fim], i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        (*comparacoes)++;
        if (vet[j] < pivo)
        {
            i++;
            (*trocas)++;
            swap(&vet[i], &vet[j]);
        }
    }

    /* Coloca o pivô em sua posição final, entre os elementos menores e maiores */
   /* Evita contar uma troca quando o pivô já está na posição correta */
    if (i + 1 != fim)
    {
        (*trocas)++;
        swap(&vet[i + 1], &vet[fim]);
    }

    return i + 1;
}

/*Implementação do QuickSort*/
void quicksort(int *vet, int inicio, int fim, ull *trocas, ull *comparacoes)
{
    while (inicio < fim)
    {
        int posPivot = particiona(vet, inicio, fim, trocas, comparacoes);
        // Otimização com Tail Recursion
        if (posPivot - inicio < fim - posPivot)
        {
            quicksort(vet, inicio, posPivot - 1, trocas, comparacoes);
            inicio = posPivot + 1;
        }
        else
        {
            quicksort(vet, posPivot + 1, fim, trocas, comparacoes);
            fim = posPivot - 1;
        }
    }
}

/*Wrap do QuickSort*/
void wrapQuickSort(int *vet, int tam, ull *trocas, ull *comparacoes)
{
    quicksort(vet, 0, tam - 1, trocas, comparacoes);
}
