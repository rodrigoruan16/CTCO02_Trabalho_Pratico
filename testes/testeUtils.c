/******************************************************************************
 * Arquivo: testeUtils.c
 *
 * Descrição: Utilitários para os testes nos algoritmos.
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - LUCAS ALEXANDRE DOS SANTOS BAESSO - 2024007172
 *            - RAFAEL FERNANDO AURELIO RIBEIRO - 2024009426
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 16/04/2025
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>
#include "testeUtils.h"
#include "testeUtils.h"

struct SORT_INFORMATIONS
{
    double time;
    double time_cpu;
    ull trocas, comparacoes;
    
};

SORT_INFORMATIONS *runTimedSort(void (*sorting_algorithm)(int *vet, int tam, ull*, ull*), int *vet, int tam)
{

    struct timeval startTime, end;
    
    clock_t inicio, fim;
    ull trocas = 0ULL, comparacoes = 0ULL;

    gettimeofday(&startTime, 0);
    inicio = clock();
    sorting_algorithm(vet, tam, &trocas, &comparacoes);
    fim = clock();
    gettimeofday(&end, 0);

    // a função retorna o valor em duas partes, uma em segundos e outra em microsegundos
    long seconds = end.tv_sec - startTime.tv_sec;
    long microseconds = end.tv_usec - startTime.tv_usec;
    double result = seconds + microseconds * 1e-6;
    double cpu_time = (double)(fim - inicio)*1000/CLOCKS_PER_SEC;

    SORT_INFORMATIONS *s = (SORT_INFORMATIONS *)malloc(sizeof(SORT_INFORMATIONS));
    s->time = result * 1000.0;
    s->time_cpu = cpu_time;
    s->trocas = trocas;
    s->comparacoes = comparacoes;

    return s;
}


double getTime(SORT_INFORMATIONS *s) {
    return s->time;
}

double getTimeCPU(SORT_INFORMATIONS *s) {
    return s->time_cpu;
}

ull getComparacoes(SORT_INFORMATIONS *s) {
    return s->comparacoes;
}

ull getTrocas(SORT_INFORMATIONS *s) {
    return s->trocas;
}
