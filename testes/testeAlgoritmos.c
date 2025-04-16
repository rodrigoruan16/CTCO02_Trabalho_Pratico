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

#include "../algoritmos/InsertionSort/InsertionSort.h"
#include "../algoritmos/MergeSort/MergeSort.h"
#include "../algoritmos/QuickSort/QuickSort.h"
#include "../algoritmos/SelectionSort/SelectionSort.h"
#include "../algoritmos/ShellSort/ShellSort.h"

#include "./testeUtils.h"
#include "../utils/utils.h"
#include "testeAlgoritmos.h"

typedef struct function
{
    void (*f)(int *, int);
    char name[50];
} function;

const int NUMBER_OF_SORT_FUNCTIONS = 5;
function functions[] = {
    {insertionsort, "Insertion Sort"},
    {selectionsort, "Selection Sort"},
    {wrapMergeSort, "Merge Sort"},
    {wrapQuickSort, "Quick Sort"},
    {shellsort, "Shell Sort"}};

void testSort(const void f(int *, int), char funcName[], int *vet, int tamanho, int porcentagem, int repeticoes)
{
    sleep(1);

    double soma = 0;
    for (int i = 0; i < repeticoes; i++)
        soma += runTimedSort(f, vet, tamanho);

    printf("%s executou em %f milissegundos.\n", funcName, soma / repeticoes);
}

int main()
{
    int tipo, tamanho, porcentagem = 0, *vet, *copy, repeticoes = 1;
    printf("1 - Gerar vetor aleatorio\n");
    printf("2 - Gerar vetor em ordem crescente\n");
    printf("3 - Gerar vetor em ordem decrescente\n");
    printf("4 - Gerar vetor em quase ordenado\n");
    printf("Digite o tipo do vetor: ");
    scanf("%d", &tipo);

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    if (tipo == 4)
    {
        printf("Digite a porcentagem para quase ordenado: ");
        scanf("%d", &porcentagem);
        repeticoes = 5;
    }

    if (tipo == 1)
        repeticoes = 5;

    vet = criaVetorTipo(tipo, tamanho, porcentagem);

    for (int i = 0; i < NUMBER_OF_SORT_FUNCTIONS; i++)
    {
        copy = copiaVetor(vet, tamanho);
        testSort(functions[i].f, functions[i].name, copy, tamanho, porcentagem, repeticoes);
    }

    return 0;
}