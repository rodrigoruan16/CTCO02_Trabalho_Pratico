#include "testeUtils.h"

struct SORT_INFORMATIONS
{
    double time;
    int trocas, comparacoes;
};

SORT_INFORMATIONS *runTimedSort(int *(*sorting_algorithm)(int *vet, int tam), int *vet, int tam)
{

    struct timeval startTime, end;
    int *vetor;

    gettimeofday(&startTime, 0);
    vetor = sorting_algorithm(vet, tam);
    gettimeofday(&end, 0);

    // a função retorna o valor em duas partes, uma em segundos e outra em microsegundos
    long seconds = end.tv_sec - startTime.tv_sec;
    long microseconds = end.tv_usec - startTime.tv_usec;
    double result = seconds + microseconds * 1e-6;

    SORT_INFORMATIONS *s = (SORT_INFORMATIONS *)malloc(sizeof(SORT_INFORMATIONS));
    s->time = result * 1000.0;
    s->trocas = vetor[0];
    s->comparacoes = vetor[1];

    return s;
}

double getTime(SORT_INFORMATIONS *s) {
    return s->time;
}

int getComparacoes(SORT_INFORMATIONS *s) {
    return s->comparacoes;
}

int getTrocas(SORT_INFORMATIONS *s) {
    return s->trocas;
}
