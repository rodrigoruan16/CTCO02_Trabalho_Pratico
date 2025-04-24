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

/**
 * Implementação do algoritmo Selection Sort
 * Ordena um vetor de inteiros em ordem crescente utilizando o método de seleção
 */
void selectionsort(int* vet, int tam, ull* trocas, ull* comparacoes)
{   
    /* Loop principal - percorre todo o vetor */
    for (int i = 0; i < tam - 1; i++)
    {
        int menor = i;

        for (int j = i + 1; j < tam; j++)
        {

            /* Se encontrar um elemento menor, atualiza o índice */
            (*comparacoes)++;
            if (vet[j] < vet[menor])
                menor = j;
        }

        /* Realiza a troca apenas se necessário */
        if (i != menor)
        {
            (*trocas)++;
            swap(&vet[i], &vet[menor]);
        }
    }
}
