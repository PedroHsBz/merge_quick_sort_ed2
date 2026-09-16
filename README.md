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


















# Merge Sort & Quick Sort — Estrutura de Dados II

Implementação dos algoritmos de ordenação **Merge Sort** e **Quick Sort** em C++, desenvolvida para o seminário da disciplina de **Estrutura de Dados II — IFTM Campus Patrocínio**.

O trabalho aborda os fundamentos dos algoritmos, suas estratégias de funcionamento, análise de complexidade e aplicação prática por meio de exercícios de programação.

## 📚 Conteúdos abordados

* Algoritmos de ordenação
* Estratégia de **Divisão e Conquista**
* **Merge Sort**
* **Quick Sort**
* Complexidade de tempo
* Complexidade de espaço
* Comparação entre os algoritmos
* Implementação prática em C++

---

## 📁 Estrutura do repositório

```text
.
├── src/
│   ├── merge_sort.cpp   # implementação do Merge Sort com main para testes
│   └── quick_sort.cpp   # implementação do Quick Sort com main para testes
└── README.md
```

---

## ⚙️ Como compilar e executar

É necessário um compilador com suporte ao **C++17**, como `g++` ou `clang++`.

### Linux / macOS

```bash
g++ -std=c++17 -O2 -Wall -Wextra src/*.cpp -o ordenacao
./ordenacao
```

### Windows (MinGW)

```bash
g++ -std=c++17 -O2 -Wall -Wextra src/*.cpp -o ordenacao.exe
ordenacao.exe
```

---

## 🧠 Resumo dos algoritmos

| Característica | Merge Sort          | Quick Sort          |
| -------------- | ------------------- | ------------------- |
| Estratégia     | Divisão e conquista | Divisão e conquista |
| Melhor caso    | O(n log n)          | O(n log n)          |
| Caso médio     | O(n log n)          | O(n log n)          |
| Pior caso      | O(n log n)          | O(n²)               |
| Espaço extra   | O(n)                | O(log n)            |
| Estável        | Sim                 | Não                 |
| In-place       | Não                 | Sim                 |

### Merge Sort

O **Merge Sort** divide o vetor sucessivamente em duas partes até chegar a subvetores com um único elemento. Depois, essas partes são combinadas em ordem crescente por meio da operação de **merge**.

Seu tempo de execução é **O(n log n)** nos casos melhor, médio e pior.

### Quick Sort

O **Quick Sort** utiliza um **pivô** para particionar o vetor. Os elementos menores ou iguais ao pivô são posicionados à esquerda e os maiores à direita. O processo é repetido recursivamente nas duas partições.

Nesta implementação, o pivô é escolhido de forma **aleatória** antes do particionamento, utilizando o esquema de **Lomuto**. Essa estratégia reduz, na prática, a probabilidade de obter partições muito desequilibradas, embora o pior caso continue sendo **O(n²)**.

---

# 📝 Questões desenvolvidas

O seminário também apresenta duas questões práticas, sendo uma para cada algoritmo de ordenação.

## Questão 1 — Ordenação com Merge Sort

A primeira questão consiste em receber um vetor de **N inteiros** e executar o **Merge Sort tradicional**, apresentando o vetor ordenado em ordem crescente.

### Funcionamento

O vetor é:

1. dividido sucessivamente ao meio;
2. separado até chegar a subvetores de um único elemento;
3. combinado novamente em ordem crescente;
4. reconstruído até formar o vetor totalmente ordenado.

### Exemplo

**Entrada:**

```text
4
4 3 2 1
```

**Saída:**

```text
1 2 3 4
```

### Resumo

A questão demonstra na prática o processo de **divisão e conquista** do Merge Sort, principalmente a etapa de **merge**, em que os elementos das duas metades são comparados e reorganizados.

---

## Questão 2 — Ordenação com Quick Sort

A segunda questão consiste em receber um vetor de **N inteiros distintos** e executar o **Quick Sort**, utilizando o último elemento do intervalo como pivô no algoritmo proposto no enunciado.

### Funcionamento

Para cada partição:

1. escolhe-se o pivô;
2. os elementos menores ou iguais ficam à esquerda;
3. os elementos maiores ficam à direita;
4. o processo é repetido recursivamente nas duas partes.

### Exemplo

**Entrada:**

```text
5
8 3 5 4 2
```

**Saída:**

```text
2 3 4 5 8
```

### Resumo

A questão demonstra na prática o **particionamento** do Quick Sort e como a escolha do pivô influencia a divisão do vetor durante a execução do algoritmo.

---

## 🔎 Comparação das questões

As duas questões trabalham o mesmo objetivo — **ordenar um vetor em ordem crescente** — mas utilizam estratégias diferentes:

* **Merge Sort:** divide o vetor em partes menores e depois realiza o processo de **merge**.
* **Quick Sort:** escolhe um **pivô** e particiona o vetor em torno dele.

Essa comparação permite observar, na prática, as diferenças entre os dois algoritmos apresentadas durante o seminário.

---

## 👥 Autores

**Grupo:** Karine, Pedro e Lucas
**Disciplina:** Estrutura de Dados II
**Instituição:** IFTM — Campus Patrocínio
**Apresentação:** 16/09/2026
