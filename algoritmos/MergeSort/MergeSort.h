/******************************************************************************
 * Arquivo: InsertionSort.h
 *
 * Descrição: Interface do algoritmo Merge Sort e auxiliares
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
typedef unsigned long long ull;

/* Interface da auxiliar merge */
void merge(int *vet, int inicio, int meio, int fim, ull *trocas, ull *comparacoes);

/*Interface do Merge Sort*/
void mergesort(int *vet, int inicio, int fim, ull *trocas, ull *comparacoes);

/*Interface do wrapper do Merge Sort*/
ull *wrapMergeSort(int *vet, int tam);
