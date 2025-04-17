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
    int pivo = vet[inicio], i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        (*comparacoes)++;
        if (vet[j] <= pivo) {
            i++;
            (*trocas)++;
            int temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
    }

    // test swap
    (*trocas)++;
    int temp = vet[i + 1];
    vet[i + 1] = vet[fim];
    vet[fim] = temp;

    return i + 1;
}

/*Implementação do QuickSort*/
void quicksort(int *vet, int inicio, int fim, int *trocas, int *comparacoes)
{
    while (inicio < fim)
    {
        int posPivot = particiona(vet, inicio, fim, trocas, comparacoes);
        // Otimização com Tail Recursion
        if(posPivot - inicio < fim - posPivot) {
            quicksort(vet, inicio, posPivot - 1, trocas, comparacoes);
            inicio = posPivot + 1;
        } else {
            quicksort(vet, posPivot + 1, fim, trocas, comparacoes);
            fim = posPivot - 1;
        }    
    }
}

/*Wrap do QuickSort*/
int *wrapQuickSort(int *vet, int tam)
{
    int trocas = 0, comparacoes = 0;
    quicksort(vet, 0, tam - 1, &trocas, &comparacoes);
    
    int *vetor = alocaVetor(2);

    if(!vetor) {
        printf("Falha ao alocar vetor no quicksort\n");
        return NULL;
    }

    vetor[0] = trocas;
    vetor[1] = comparacoes;

    return vetor;
}
