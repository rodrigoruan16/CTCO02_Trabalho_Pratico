/******************************************************************************
 * Arquivo: algoritmos.h
 * 
 * Descrição: Declarações dos algoritmos de ordenação para o sistema de benchmarking.
 *            Contém as interfaces das funções de ordenação e estruturas de dados
 *            auxiliares necessárias para a análise de desempenho.
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

/*Implementação do InsertionSort*/
void insertionsort(int *vet, int tam);

/*Implementação do SelectionSort*/
void selectionsort(int *vet, int tam);

/* Implementação do merge (auxiliar para mergesort) */
void merge(int *vet, int low, int mid, int high);

/*Implementação do MergeSort*/
void mergesort(int *vet, int low, int high);

/*Wrap do MergeSort que converte os args padrão para o adaptado*/
void wrapMergeSort(int *vet, int tam);

/*Implementação do QuickSort*/
void quicksort(int *vet, int inicio, int fim, int *contador);

/* Implementação do particiona (auxiliar para quicksort) */
int particiona(int *vet, int inicio, int fim);
