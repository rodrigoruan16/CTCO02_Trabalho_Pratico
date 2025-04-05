#include "testeUtils.h"

int runTimedSort(void (*sorting_algorithm)(int *vet, int tam), int *vet, int tam) {
    clock_t startTime = clock();
    sorting_algorithm(vet, tam);
    clock_t end = clock();

    double result = (double) (end - startTime) / CLOCKS_PER_SEC;
    return result * 1000; // ms
}
