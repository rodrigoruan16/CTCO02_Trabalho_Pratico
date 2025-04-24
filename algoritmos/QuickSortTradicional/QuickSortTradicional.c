/******************************************************************************
 * Arquivo: QuickSort.c
 *
 * Descrição: Implementação do Quick Sort Tradicional
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
#include "QuickSortTradicional.h"

/**
 * Função de particionamento para o algoritmo QuickSort (versão tradicional)
 * Esta função seleciona o primeiro elemento como pivô e rearranja o vetor
 * de forma que elementos menores que o pivô fiquem à esquerda e maiores à direita
*/
int particionatrad(int *vet, int inicio, int fim, ull *trocas, ull *comparacoes)
{
    int pivo = vet[inicio], i = inicio;

    for (int j = inicio + 1; j <= fim; j++)
    {
        (*comparacoes)++;
        if (vet[j] < pivo) {
            i++;
            
            if(i!=j) {
                (*trocas)++;
                swap(&vet[i], &vet[j]);
            }
        }
    }

    (*trocas)++;
    swap(&vet[inicio], &vet[i]);  // Troca o pivô para sua posição final
    return i;  // Retorna a posição do pivô
}

/*Implementação do QuickSort Tradicional*/
void quicksorttrad(int *vet, int inicio, int fim, ull *trocas, ull *comparacoes)
{
    if (inicio < fim)
    {
        int posPivot = particionatrad(vet, inicio, fim, trocas, comparacoes);
        quicksorttrad(vet, inicio, posPivot - 1, trocas, comparacoes);
        quicksorttrad(vet, posPivot + 1, fim, trocas, comparacoes);
    }
}


/*Wrap do QuickSort Tradicional*/
void wrapQuickSorttrad(int *vet, int tam, ull *trocas, ull *comparacoes)
{
    quicksorttrad(vet, 0, tam - 1, trocas, comparacoes);
}
