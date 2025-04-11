#include <stdio.h>
#include <stdlib.h>
#include "./algoritmos/algoritmos.h"

int main() {
    int vet[] = {1, 2, 3, -56, 234, 293829, -23, 212, 909};

    int contador = 0;

    shellsort(vet, sizeof(vet)/sizeof(int));

    for (int i = 0; i < sizeof(vet)/sizeof(int); i++) {
        printf("%d ", vet[i]);
    }

    printf("\n");

    return 0;
}