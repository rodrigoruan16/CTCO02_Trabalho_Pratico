#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

double runTimedSort(void (*sorting_algorithm)(int *vet, int tam), int *vet, int tam);