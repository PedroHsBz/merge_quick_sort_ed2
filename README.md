# Merge Sort & Quick Sort — Estrutura de Dados II

Implementação própria dos algoritmos **Merge Sort** e **Quick Sort** em C++,
desenvolvida para o seminário da disciplina de Estrutura de Dados II sobre
algoritmos avançados de ordenação.

## Estrutura do repositório

```
.
├── src/
│   ├── merge_sort.cpp   # implementação do Merge Sort com main para testes
│   └── quick_sort.cpp   # implementação do Quick Sort com main para testes
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

Grupo: Karine, Pedro e Lucas — Estrutura de Dados II — IFTM Campus Patrocínio
Apresentação: 16/09/2026
