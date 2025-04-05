#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int runTimedSort(void (*sorting_algorithm)(int *vet, int tam), int *vet, int tam);