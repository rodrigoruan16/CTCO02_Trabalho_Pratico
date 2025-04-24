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
#include <string.h>

#include "../algoritmos/InsertionSort/InsertionSort.h"
#include "../algoritmos/MergeSort/MergeSort.h"
#include "../algoritmos/QuickSort/QuickSort.h"
#include "../algoritmos/QuickSortTradicional/QuickSortTradicional.h"
#include "../algoritmos/SelectionSort/SelectionSort.h"
#include "../algoritmos/ShellSort/ShellSort.h"

#include "./testeUtils.h"
#include "../utils/utils.h"
#include "testeAlgoritmos.h"

typedef struct function
{
    void (*f)(int *, int, ull *, ull *);
    char name[50];
} function;

const int NUMBER_OF_SORT_FUNCTIONS = 6;
function functions[] = {
    {insertionsort, "Insertion Sort"},
    {selectionsort, "Selection Sort"},
    {wrapMergeSort, "Merge Sort"},
    {wrapQuickSort, "Quick Sort"},
    {shellsort, "Shell Sort"},
    {wrapQuickSorttrad, "QuickSort Tradicional"}    
};

void testSort(void f(int *, int, ull *, ull *), char funcName[], int *vet, int tamanho, int porcentagem, int repeticoes, char tipoVet[])
{
    double soma = 0, soma_cpu = 0;
    ull trocas = 0, comparacoes = 0;
    int *copy;
    SORT_INFORMATIONS *s;

    for (int i = 0; i < repeticoes; i++)
    {
        copy = copiaVetor(vet, tamanho);

        if (!copy)
        {
            printf("Falha ao alocar vetor para %s\n", funcName);
            return;
        }

        s = runTimedSort(f, copy, tamanho);
        soma += getTime(s);
        soma_cpu += getTimeCPU(s);
        trocas += getTrocas(s);
        comparacoes += getComparacoes(s);
        free(copy);
        free(s);
    }

    double time = soma / repeticoes;
    double time_CPU = soma_cpu / repeticoes;
    escreveArquivo("resultados.csv", funcName, time, time_CPU, tamanho, comparacoes / repeticoes, trocas / repeticoes, tipoVet);
    printf("%s executou em %f milissegundos.\n", funcName, time);
    printf("%s utilizou a CPU por %f milissegundos.\n", funcName, time_CPU);
    printf("Trocas: %llu - Comparações: %llu\n", trocas / repeticoes, comparacoes / repeticoes);
}

int main()
{
    int tipo, tamanho, porcentagem = 0, *vet, repeticoes = 1;
    char str_tipo[10];
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
    if (!vet)
    {
        printf("Falha ao alocar vetor.\n");
        return 0;
    }

    if (sprintf(str_tipo, "%d_%d", tipo, porcentagem) == 0)
    {
        strcpy(str_tipo, " ");
    }

    for (int i = 0; i < NUMBER_OF_SORT_FUNCTIONS; i++)
        testSort(functions[i].f, functions[i].name, vet, tamanho, porcentagem, repeticoes, str_tipo);

    free(vet);

    return 0;
}
