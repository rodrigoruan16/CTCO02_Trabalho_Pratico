/******************************************************************************
 * Arquivo: utils.h
 *
 * Descrição: Biblioteca utilitária para geração de dados e operações de apoio
 *            ao sistema de benchmarking de algoritmos de ordenação. Contém
 *            funções para criação de conjuntos de dados e auxiliares de arquivo.
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

/* Aloca um vetor de tamanho @tam */
int *alocaVetor(int tam);

/* Cria cópia de um vetor */
int *copiaVetor(int *vet, int tam);

/*O sistema deve gerar conjuntos de dados ordenados de forma crescente e
decrescente. Para tanto, deve haver uma função com a assinatura abaixo, onde
tam é a quantidade de elementos e ordem define o tipo de ordenação: 0 para
ordem crescente e 1 para ordem decrescente. A função retorna o vetor
previamente preenchido.*/
int *geraOrdenados(int tam, int ordem);

/*O sistema deve gerar conjuntos de dados quase ordenados, que contém cerca
de 10% dos dados desordenados 90% ordenados. Para tanto, deve haver uma
função com a assinatura abaixo, onde tam é a quantidade de elementos que
deve ser gerada e a porcentagem é o inteiro que determina a porcentagem de
dados desordenados. A função retorna o vetor previamente preenchido.*/
int *geraQuaseOrdenados(int tam, int porcentagem);

/*O sistema deve gerar conjuntos de dados aleatórios de diferentes tamanhos.
Para tanto, deve haver uma função com a assinatura abaixo, onde tam é a
quantidade de elementos que deve ser gerada e a semente é o inteiro que
permite que esse conjunto de dados seja reproduzido posteriormente. A função
retorna o vetor previamente preenchido.*/
int *geraAleatorios(int tam, int semente);

/* Printa os elementos de um vetor */
void printaVetor(int *vet, int tam);

/*Cria vetor a ser ordenado lendo o arquivo
  Será responsável por criar o vetor que será
  utilizado em todas as demais funções
*/
int *leArquivo(char *nomeArquivo, int qtd);

/* Cria o arquivo de resultado final.
    Vamos usar para fazer os gráficos e a apresentação
    Deve conter:
    tempo de execução
    tamanho da entrada
    algoritmo utilizado
    ...
    ..
    .
    etc
*/
void escreveArquivo(char *nomeArquivo, char *nomeAlgo, int exec_time, int inputSize);

/*Esta função implementa a busca binária e sua saída é salva no vetor res
  res[0] recebe 1 se encontrou o elemento buscado e 0 caso contrário
  res[1] informa quantas vezes a função buscaBinaria foi chamada, uma vez que ela é recursiva
  ou seja, sempre que a função é chamada res[1] é incrementado*/
void buscaBinaria(int *vet, int inicio, int fim, int valor, int *res);

/* Compare auxiliar para in-built quicksort (increasing) */
int compare(const void *a, const void *b);

/* Verifica se ambos vetores são iguais (mesmos elementos nas mesmas posições) */
int areEqual(int *a, int *b, int qtyElementos);

/* Helper para criar vetor em ordem crescente, decrescente, aleatorio e quase aleatorio */
int *criaVetorTipo(int tipo, int tamanho, int porcentagem);