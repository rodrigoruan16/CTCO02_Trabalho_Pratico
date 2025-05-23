/******************************************************************************
 * Arquivo: testeAlgoritmos.c
 *
 * Descrição: Testes unitários para os algoritmos de ordenação implementados
 *            em algoritmos.c. Este arquivo contém os casos de teste para
 *            verificar a corretude e robustez das funções de ordenação.
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
typedef struct function function;

void testSort(void f(int *, int, ull*, ull*), char funcName[], int *vet, int tamanho, int porcentagem, int repeticoes, char tipoVet[]);