#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

typedef struct SORT_INFORMATIONS SORT_INFORMATIONS;

SORT_INFORMATIONS * runTimedSort(int* (*sorting_algorithm)(int *vet, int tam), int *vet, int tam);
double getTime(SORT_INFORMATIONS *s);
int getComparacoes(SORT_INFORMATIONS *s);
int getTrocas(SORT_INFORMATIONS *s);