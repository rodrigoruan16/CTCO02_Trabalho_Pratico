#include "testeUtils.h"

double runTimedSort(void (*sorting_algorithm)(int *vet, int tam), int *vet, int tam) {

    struct timeval startTime, end;

    gettimeofday(&startTime, 0);    
    sorting_algorithm(vet, tam);
    gettimeofday(&end, 0);

    // a função retorna o valor em duas partes, uma em segundos e outra em microsegundos
    long seconds = end.tv_sec - startTime.tv_sec;
    long microseconds = end.tv_usec - startTime.tv_usec;
    double result = seconds + microseconds*1e-6;
    return result * 1000.0; // ms
}
