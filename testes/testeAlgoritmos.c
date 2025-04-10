/******************************************************************************
 * Arquivo: testeAlgoritmos.c
 * 
 * Descrição: Testes unitários para os algoritmos de ordenação implementados
 *            em algoritmos.c. Este arquivo contém os casos de teste para
 *            verificar a corretude e robustez das funções de ordenação.
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
#include <time.h>
#include <assert.h>
#include "testeUtils.h"
#include "../utils/utils.h"
#include "../algoritmos/algoritmos.h"

void testSort() {
    srand(time(NULL));

    int acertos = 0, total = 0;
 
    for (int i = 0; i < (rand() % 100) + 10; i++) {
        int qtyElementos = (rand() % 10) + 10, value;
        int *vet = alocaVetor(qtyElementos), *copy = alocaVetor(qtyElementos);

        for (int j = 0, k = qtyElementos - 1; j < qtyElementos; j++, k--) {
            value = (rand() % 10000);
            vet[j] = value;
            copy[k] = value;
        }

        insertionsort(vet, qtyElementos);
        qsort(&copy[0], qtyElementos, sizeof(int), compare);

        int equal = areEqual(vet, copy, qtyElementos);
        if (equal) {
            acertos++;
        }

        printaVetor(vet, qtyElementos);
        printaVetor(copy, qtyElementos);
        printf("Ordenados corretamente: %s\n", (equal == 1 ? "Sim" : "Nao"));

        total++;
    }

    printf("-- Insertion sort --\n");
    printf("Total de testes: %d\n", total);
    printf("Total de ordenacoes corretas: %d\n", acertos);
    printf("Porcentagem de ordenacoes corretas: %.2f\n", acertos/(float)total * 100);
}

int main() {
    testSort();
}