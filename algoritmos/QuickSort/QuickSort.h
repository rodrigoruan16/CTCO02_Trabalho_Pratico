/******************************************************************************
 * Arquivo: SelectionSort.h
 *
 * Descrição: Interface do algoritmo Quick Sort e auxiliares
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

/* Interface do auxiliar particiona */
int particiona(int *vet, int inicio, int fim, int *trocas, int *comparacoes);

/* Interface do Quick Sort */
void quicksort(int *vet, int inicio, int fim, int *trocas, int *comparacoes);

/* Interface do wrapper do Quick Sort */
int *wrapQuickSort(int *vet, int tam);
