# Benchmarking de Algoritmos de Ordenação

Este repositório contém um sistema de _benchmarking_ desenvolvido em C para comparar o desempenho de algoritmos de ordenação em diferentes cenários de dados. O projeto foi realizado como parte da disciplina **Algoritmos e Estruturas de Dados II** da **Universidade Federal de Itajubá**.

---

## 📌 Objetivo
Comparar a eficiência dos seguintes algoritmos de ordenação:
- **Inserção** (`insertionSort`)
- **Seleção** (`selectionSort`)
- **MergeSort** (`mergeSort`)
- **QuickSort Tradicional** (`quickSort`)
- **Algoritmo Novo**: **???** (`???`)

**Métricas avaliadas**:
- Tempo de execução (ms).
- Número de comparações.
- Número de trocas/cópias.

---

## 🛠️ Funcionalidades
1. **Geração de Dados**:
   - Vetores aleatórios (`geraAleatorios`).
   - Vetores quase ordenados (`geraQuaseOrdenados`).
   - Vetores ordenados (crescente/decrescente, `geraOrdenados`).

2. **Execução de _Benchmarking_**:
   - Testes para tamanhos de entrada variados (ex.: 1000, 10000, 100000 elementos).
   - Tipos de ordenação: aleatório, crescente, decrescente, quase ordenado (média de 5 repetições).

3. **Saída**:
   - Tabelas comparativas (exemplo abaixo) e gráficos para cada métrica.

| Tamanho | Aleatório (ms) | Crescente (ms) | Decrescente (ms) | Quase Ordenado (ms) |
|---------|----------------|----------------|------------------|---------------------|
| 1000    | 2.1            | 0.5            | 1.8              | 1.2                 |

---

