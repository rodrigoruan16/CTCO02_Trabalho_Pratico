#include <stdio.h>
#include <stdlib.h>
#include "./algoritmos/algoritmos.h"

int main() {
    int vet[] = {1, 2, 3, -56, 234, 293829, 212, 909};

    int contador = 0;

    wrapMergeSort(vet, sizeof(vet)/sizeof(int)-1);

    for (int i = 0; i < sizeof(vet)/sizeof(int); i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}