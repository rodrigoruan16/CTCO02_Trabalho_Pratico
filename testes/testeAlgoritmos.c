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
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#include "testeUtils.h"
#include "../utils/utils.h"
#include "../algoritmos/algoritmos.h"
#include "testeAlgoritmos.h"

typedef struct function {
    void (*f)(int*, int);
    char name[50];
} function;

// VARIAVEIS RELACIONADAS AOS TESTES! //

const int NUMBER_OF_SORT_FUNCTIONS = 4;
const int NUMBER_OF_TESTS = 10;
const int MAX_VECTOR_NUMBER = INT_MAX;
const int MAX_NUMBER_OF_ELEMENTS_IN_VECTOR = 10;
function functions[] = {
    {insertionsort, "Insertion Sort"},
    {selectionsort, "Selection Sort"},
    {wrapMergeSort, "Merge Sort"},
    {wrapQuickSort, "Quick Sort"}
};

// ---------------------------------- //

void testSort(const void f(int *, int), char funcName[]) {
    srand(time(NULL));

    sleep(1);

    int acertos = 0, total = 0;
 
    for (int i = 0; i < NUMBER_OF_TESTS; i++) {
        int qtyElementos = MAX_NUMBER_OF_ELEMENTS_IN_VECTOR, value;
        int *vet = alocaVetor(qtyElementos), *copy = alocaVetor(qtyElementos);

        for (int j = 0, k = qtyElementos - 1; j < qtyElementos; j++, k--) {
            value = (rand() % MAX_VECTOR_NUMBER);
            vet[j] = value;
            copy[k] = value;
        }
        
        f(vet, qtyElementos);
        qsort(&copy[0], qtyElementos, sizeof(int), compare);

        int equal = areEqual(vet, copy, qtyElementos);
        if (equal) {
            acertos++;
        }

        total++;
    }

    printf("-- %s --\n", funcName);
    printf("Total de testes: %d\n", total);
    printf("Total de testes: %d\n", total);
    printf("Total de ordenacoes corretas: %d\n", acertos);
    printf("Porcentagem de ordenacoes corretas: %.2f\n", acertos/(float)total * 100);
}

int main() {
    for (int i = 0; i < NUMBER_OF_SORT_FUNCTIONS; i++)
        testSort(functions[i].f, functions[i].name);

    return 0;
}