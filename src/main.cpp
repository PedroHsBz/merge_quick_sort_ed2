#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "merge_sort.hpp"
#include "quick_sort.hpp"

// Imprime um vetor no formato [a, b, c, ...]. Trunca vetores grandes
// para manter a saída legível.
static void imprimir(const std::string& rotulo, const std::vector<int>& v, size_t limite = 15) {
    std::cout << rotulo << ": [";
    size_t n = std::min(v.size(), limite);
    for (size_t i = 0; i < n; ++i) {
        std::cout << v[i];
        if (i + 1 < n) std::cout << ", ";
    }
    if (v.size() > limite) std::cout << ", ...";
    std::cout << "]  (tamanho = " << v.size() << ")\n";
}

// Verifica se o vetor está ordenado de forma não decrescente.
static bool estaOrdenado(const std::vector<int>& v) {
    return std::is_sorted(v.begin(), v.end());
}

// Gera um vetor com 'n' elementos aleatórios no intervalo [0, maxValor].
static std::vector<int> gerarVetorAleatorio(int n, int maxValor = 10000) {
    std::vector<int> v(n);
    std::mt19937 gerador(42); // semente fixa: resultados reproduzíveis
    std::uniform_int_distribution<int> dist(0, maxValor);
    for (int& x : v) x = dist(gerador);
    return v;
}

// Mede o tempo (em milissegundos) para ordenar uma cópia de 'v' usando
// a função de ordenação passada como parâmetro.
template <typename FuncaoOrdenacao>
static double medirTempoMs(std::vector<int> v, FuncaoOrdenacao ordenar) {
    auto inicio = std::chrono::high_resolution_clock::now();
    ordenar(v);
    auto fim = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(fim - inicio).count();
}

int main() {
    std::cout << "===========================================\n";
    std::cout << " Merge Sort & Quick Sort - Casos de teste\n";
    std::cout << "===========================================\n\n";

    // ---------------------------------------------------------------
    // Caso 1: vetor pequeno e simples, para ver a ordenação de perto
    // ---------------------------------------------------------------
    {
        std::cout << "--- Caso 1: vetor pequeno ---\n";
        std::vector<int> original = {8, 3, 5, 1, 9, 2, 7, 4};

        std::vector<int> comMerge = original;
        mergeSort(comMerge);
        imprimir("Original        ", original);
        imprimir("Merge Sort  -> ", comMerge);
        std::cout << (estaOrdenado(comMerge) ? "OK: ordenado\n" : "ERRO: nao ordenado\n");

        std::vector<int> comQuick = original;
        quickSort(comQuick);
        imprimir("Quick Sort  -> ", comQuick);
        std::cout << (estaOrdenado(comQuick) ? "OK: ordenado\n" : "ERRO: nao ordenado\n");
        std::cout << "\n";
    }

    // ---------------------------------------------------------------
    // Caso 2: vetor já ordenado (melhor caso para Merge Sort;
    // com pivô fixo seria o pior caso para Quick Sort, mas aqui usamos
    // pivô aleatório justamente para evitar essa degradação)
    // ---------------------------------------------------------------
    {
        std::cout << "--- Caso 2: vetor ja ordenado ---\n";
        std::vector<int> original(20);
        for (int i = 0; i < 20; ++i) original[i] = i;

        std::vector<int> comMerge = original;
        mergeSort(comMerge);
        std::cout << (estaOrdenado(comMerge) ? "Merge Sort OK\n" : "Merge Sort ERRO\n");

        std::vector<int> comQuick = original;
        quickSort(comQuick);
        std::cout << (estaOrdenado(comQuick) ? "Quick Sort OK\n" : "Quick Sort ERRO\n");
        std::cout << "\n";
    }

    // ---------------------------------------------------------------
    // Caso 3: vetor em ordem decrescente
    // ---------------------------------------------------------------
    {
        std::cout << "--- Caso 3: vetor em ordem decrescente ---\n";
        std::vector<int> original(20);
        for (int i = 0; i < 20; ++i) original[i] = 20 - i;

        std::vector<int> comMerge = original;
        mergeSort(comMerge);
        std::cout << (estaOrdenado(comMerge) ? "Merge Sort OK\n" : "Merge Sort ERRO\n");

        std::vector<int> comQuick = original;
        quickSort(comQuick);
        std::cout << (estaOrdenado(comQuick) ? "Quick Sort OK\n" : "Quick Sort ERRO\n");
        std::cout << "\n";
    }

    // ---------------------------------------------------------------
    // Caso 4: vetor com elementos repetidos (testa estabilidade e
    // corretude do particionamento com valores iguais)
    // ---------------------------------------------------------------
    {
        std::cout << "--- Caso 4: vetor com elementos repetidos ---\n";
        std::vector<int> original = {5, 1, 5, 2, 5, 1, 3, 5, 2};

        std::vector<int> comMerge = original;
        mergeSort(comMerge);
        imprimir("Merge Sort  -> ", comMerge);

        std::vector<int> comQuick = original;
        quickSort(comQuick);
        imprimir("Quick Sort  -> ", comQuick);
        std::cout << "\n";
    }

    // ---------------------------------------------------------------
    // Caso 5: vetor vazio e vetor com um único elemento (casos base)
    // ---------------------------------------------------------------
    {
        std::cout << "--- Caso 5: casos extremos (vazio e unitario) ---\n";
        std::vector<int> vazio;
        mergeSort(vazio);
        quickSort(vazio);
        std::cout << "Vetor vazio ordenado sem erros. Tamanho: " << vazio.size() << "\n";

        std::vector<int> unico = {42};
        mergeSort(unico);
        quickSort(unico);
        imprimir("Vetor unitario  -> ", unico);
        std::cout << "\n";
    }

    // ---------------------------------------------------------------
    // Caso 6: comparação de desempenho com vetor aleatório grande
    // ---------------------------------------------------------------
    {
        std::cout << "--- Caso 6: desempenho com vetor aleatorio grande ---\n";
        const int n = 20000;
        std::vector<int> original = gerarVetorAleatorio(n);

        double tempoMerge = medirTempoMs(original, [](std::vector<int>& v) { mergeSort(v); });
        double tempoQuick = medirTempoMs(original, [](std::vector<int>& v) { quickSort(v); });

        std::cout << "Tamanho do vetor: " << n << "\n";
        std::cout << "Merge Sort: " << tempoMerge << " ms\n";
        std::cout << "Quick Sort: " << tempoQuick << " ms\n";
    }

    return 0;
}
