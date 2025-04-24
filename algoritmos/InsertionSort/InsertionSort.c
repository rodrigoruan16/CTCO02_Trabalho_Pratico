/******************************************************************************
 * Arquivo: InsertionSort.c
 *
 * Descrição: Implementação do Insertion Sort
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
#include <stdlib.h>
#include "../../utils/utils.h"
#include "InsertionSort.h"

/**
* Implementação do algoritmo InsertionSort
* Ordena um vetor de inteiros em ordem crescente utilizando o método de inserção
*/
void insertionsort(int* vet, int tam, ull* trocas, ull* comparacoes)
{
    /* Loop principal - percorre o vetor a partir do segundo elemento */
    for (int i = 1; i < tam; i++)
    {
        int marcador = i - 1;
        int elemento = vet[i];

        (*comparacoes)++; // Comparacao entre vet[marcador] e elemento
        /* Desloca elementos maiores que 'elemento' para a direita */
        while (marcador >= 0 && vet[marcador] > elemento)
        {
            vet[marcador + 1] = vet[marcador];
            marcador--;

            /* Contabiliza a próxima comparação se ainda houver elementos para comparar */
            if (marcador >= 0)
                (*comparacoes)++;
        }

        vet[marcador + 1] = elemento;
    }
}
