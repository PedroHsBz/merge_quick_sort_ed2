# Merge Sort & Quick Sort — Estrutura de Dados II

Implementação própria dos algoritmos **Merge Sort** e **Quick Sort** em C++,
desenvolvida para o seminário da disciplina de Estrutura de Dados II sobre
algoritmos avançados de ordenação.

## Estrutura do repositório

```
.
├── include/
│   ├── merge_sort.hpp   # declarações do Merge Sort
│   └── quick_sort.hpp   # declarações do Quick Sort
├── src/
│   ├── merge_sort.cpp   # implementação do Merge Sort
│   ├── quick_sort.cpp   # implementação do Quick Sort
│   └── main.cpp         # casos de teste e comparação de desempenho
└── README.md
```

## Como compilar e executar

É necessário um compilador com suporte a C++17 (g++ ou clang++).

```bash
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/*.cpp -o ordenacao
./ordenacao
```

No Windows (MinGW), o processo é o mesmo, apenas ajustando o nome do executável:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -Iinclude src/*.cpp -o ordenacao.exe
ordenacao.exe
```

## O que os testes em `main.cpp` cobrem

| Caso | O que valida |
|---|---|
| 1 | Ordenação de um vetor pequeno, com saída antes/depois |
| 2 | Vetor já ordenado (melhor caso teórico) |
| 3 | Vetor em ordem decrescente |
| 4 | Vetor com elementos repetidos |
| 5 | Casos extremos: vetor vazio e vetor de 1 elemento |
| 6 | Comparação de tempo de execução com um vetor aleatório grande (20.000 elementos) |

## Resumo dos algoritmos

| | Merge Sort | Quick Sort |
|---|---|---|
| Complexidade (melhor caso) | O(n log n) | O(n log n) |
| Complexidade (caso médio) | O(n log n) | O(n log n) |
| Complexidade (pior caso) | O(n log n) | O(n²) |
| Espaço extra | O(n) | O(log n) |
| Estável | Sim | Não |
| In-place | Não | Sim |

O Quick Sort implementado usa **escolha aleatória de pivô** antes do
particionamento (esquema de Lomuto), reduzindo na prática a chance de cair
no pior caso O(n²) mesmo em entradas já ordenadas.

## Autores

Grupo — Estrutura de Dados II — IFTM Campus Patrocínio
Apresentação: 16/09/2026
