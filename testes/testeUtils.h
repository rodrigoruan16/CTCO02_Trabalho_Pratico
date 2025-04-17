/******************************************************************************
 * Arquivo: testeUtils.h
 *
 * Descrição: Interfaces para utilitários para os testes nos algoritmos.
 *
 * Criadores:
 *            - CAIO MENDES COUTINHO E GARCIA - 2024007305
 *            - DIEGO SILVA CORTEZ - 2024002480
 *            - LUCAS ALEXANDRE DOS SANTOS BAESSO - 2024007172
 *            - RAFAEL FERNANDO AURELIO RIBEIRO - 2024009426
 *            - RODRIGO RUAN SOUZA VIANA - 2024004644
 *
 * Data: 16/04/2025
 ******************************************************************************/
typedef unsigned long long ull;
typedef struct SORT_INFORMATIONS SORT_INFORMATIONS;

SORT_INFORMATIONS * runTimedSort(ull* (*sorting_algorithm)(int *vet, int tam), int *vet, int tam);
double getTime(SORT_INFORMATIONS *s);
ull getComparacoes(SORT_INFORMATIONS *s);
ull getTrocas(SORT_INFORMATIONS *s);