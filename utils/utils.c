/******************************************************************************
 * Arquivo: utils.c
 *
 * Descrição: Implementação das funções utilitárias para geração de dados e
 *            operações de arquivo do sistema de benchmarking.
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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // acesso a access()
#include <time.h>
#include "utils.h"

/* Aloca um vetor de tamanho @tam */
int *alocaVetor(int tam)
{
    if (tam <= 0)
        return NULL;

    int *vetor = (int *)malloc(sizeof(int) * tam);

    if (!vetor)
        return NULL;

    return vetor;
}

/* Realiza a troca de dois elementos */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Cria cópia de um vetor */
int *copiaVetor(int *vet, int tam)
{
    if (tam <= 0)
        return NULL;

    int *vetor = alocaVetor(tam);
    if (!vetor)
        return NULL;

    for (int i = 0; i < tam; i++)
        vetor[i] = vet[i];

    return vetor;
}

/* Printa os elementos de um vetor */
void printaVetor(int *vet, int tam)
{
    if (!vet || tam <= 0)
        return;

    for (int i = 0; i < tam; i++)
        printf("%d ", vet[i]);

    printf("\n");
}

/*O sistema deve gerar conjuntos de dados ordenados de forma crescente e
decrescente. Para tanto, deve haver uma função com a assinatura abaixo, onde
tam é a quantidade de elementos e ordem define o tipo de ordenação: 0 para
ordem crescente e 1 para ordem decrescente. A função retorna o vetor
previamente preenchido.*/
int *geraOrdenados(int tam, int ordem)
{
    if (tam <= 0 || (ordem != 1 && ordem != 0))
        return NULL;

    int *vetor = alocaVetor(tam);
    if (!vetor)
        return NULL;

    for (int i = 0; i < tam; i++)
        vetor[i] = (ordem == 0 ? i + 1 : tam - i);

    return vetor;
}

/*O sistema deve gerar conjuntos de dados quase ordenados, que contém cerca
de 10% dos dados desordenados 90% ordenados. Para tanto, deve haver uma
função com a assinatura abaixo, onde tam é a quantidade de elementos que
deve ser gerada e a porcentagem é o inteiro que determina a porcentagem de
dados desordenados. A função retorna o vetor previamente preenchido.*/
int *geraQuaseOrdenados(int tam, int porcentagem)
{
    int *vet, numDesordenados, idx1, idx2, temp;
    if (tam <= 0 || porcentagem < 0 || porcentagem > 100)
        return NULL;

    vet = geraOrdenados(tam, 0);
    if (!vet)
        return NULL;

    numDesordenados = (tam * porcentagem) / 100;

    srand(time(NULL));

    for (int i = 0; i < numDesordenados; i++)
    {
        idx1 = rand() % tam, idx2 = rand() % tam;
        temp = vet[idx1];
        vet[idx1] = vet[idx2];
        vet[idx2] = temp;
    }

    return vet;
}

/*O sistema deve gerar conjuntos de dados aleatórios de diferentes tamanhos.
Para tanto, deve haver uma função com a assinatura abaixo, onde tam é a
quantidade de elementos que deve ser gerada e a semente é o inteiro que
permite que esse conjunto de dados seja reproduzido posteriormente. A função
retorna o vetor previamente preenchido.*/
int *geraAleatorios(int tam, int semente)
{
    if (tam <= 0)
        return NULL;

    srand(semente);

    int *vetor = alocaVetor(tam);
    if (!vetor)
        return NULL;

    for (int i = 0; i < tam; i++)
        vetor[i] = rand();

    return vetor;
}

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
void escreveArquivo(char *nomeArquivo, char *nomeAlgo, double exec_time, double exec_time_cpu, int inputSize, int comparacoes, int trocas, char *tipoVet)
{
    FILE *arq;
    int arquivoExiste = 0;
    if (access(nomeArquivo, F_OK) == 0)
        arquivoExiste = 1;

    arq = fopen(nomeArquivo, arquivoExiste ? "a" : "w");
    if (!arq)
        return;

    if (!arquivoExiste)
    {
        fprintf(arq, "Tipo da Entrada;Nome do Algoritmo;Tamanho da Entrada;Tempo de Execucao(ms);Tempo CPU(ms); Trocas; Comparacoes\n");
    }

    fprintf(arq, "%s;%s;%d;%lf;%lf;%llu;%llu\n", tipoVet, nomeAlgo, inputSize, exec_time, exec_time_cpu, trocas, comparacoes);
    fclose(arq);
};

/*Esta função implementa a busca binária e sua saída é salva no vetor res
  res[0] recebe 1 se encontrou o elemento buscado e 0 caso contrário
  res[1] informa quantas vezes a função buscaBinaria foi chamada, uma vez que ela é recursiva
  ou seja, sempre que a função é chamada res[1] é incrementado*/
void buscaBinaria(int *vet, int inicio, int fim, int valor, int *res)
{
    res[1]++;
    if (!vet || inicio > fim)
        return;

    int meio = (inicio + fim) / 2;

    if (vet[meio] == valor)
    {
        res[0] = 1;
        return;
    }

    if (vet[meio] < valor)
    {
        buscaBinaria(vet, meio + 1, fim, valor, res);
    }
    else
    {
        buscaBinaria(vet, inicio, meio - 1, valor, res);
    }
}

/* Compare auxiliar para in-built quicksort (increasing) */
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/* Verifica se ambos vetores são iguais (mesmos elementos nas mesmas posições) */
int areEqual(int *a, int *b, int qtyElementos)
{
    for (int i = 0; i < qtyElementos; i++)
    {
        if (a[i] != b[i])
            return 0;
    }

    return 1;
}

/*
    Helper para criar vetor em ordem crescente, decrescente, aleatorio e quase aleatorio;
    1 - Para vetor aleatório
    2 - Para vetor em ordem crescente
    3 - para vetor em ordem decrescente
    4 - para vetor quase ordenado
*/
int *criaVetorTipo(int tipo, int tamanho, int porcentagem)
{
    int *vet, crescente = tipo == 1;

    switch (tipo)
    {
    case 1:
        vet = geraAleatorios(tamanho, time(NULL));
        break;

    case 2:
        vet = geraOrdenados(tamanho, 0);
        break;

    case 3:
        vet = geraOrdenados(tamanho, 1);
        break;

    case 4:
        vet = geraQuaseOrdenados(tamanho, porcentagem);
        break;

    default:
        break;
    }

    return vet;
}
