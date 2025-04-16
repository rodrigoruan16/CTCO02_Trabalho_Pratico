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
#include "InsertionSort.h"

/*Implementação do InsertionSort*/
void insertionsort(int *vet, int tam)
{
    if (!vet || tam == 0)
        return;

    for (int i = 1; i < tam; i++)
    {
        int marcador = i - 1, elemento = vet[i];

        while (marcador >= 0 && vet[marcador] > elemento)
        {
            vet[marcador + 1] = vet[marcador];
            marcador--;
        }

        vet[marcador + 1] = elemento;
    }
}
