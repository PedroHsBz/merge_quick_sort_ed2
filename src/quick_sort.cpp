#include <iostream>
#include <vector>
using namespace std;

// Metodo partition que recebe o nosso vetor arr, o index low (que é o menor index) e o high (que é o maior)
int partition(vector<int>& arr, int low, int high) {

    // Escolhe um pivô, ou um ponto de referência, que nesse caso é o último elemento do intervalo
    int pivot = arr[high];

    // Variável auxiliar que vai ser utilizada nas trocas de elementos, ela se refere ao menor index
    // Ou seja, se começar no 0 o i = -1 ou se começar no 5 o i = 4
    int i = low - 1;

    // Temos um laço de repetição (FOR) que vai rodar enquanto o j=low for menor ou igual ao maior index high - 1
    for (int j = low; j <= high - 1; j++) {
        // Verificamos se o elemento da posição j é menor que o pivô
        if (arr[j] < pivot) {
            // Se caso for, o valor de i é aumentado, por exemplo: na primeira vez que rodar, no caso i=-1, é necessário aumentar o i
            i++;
            // Trocamos os elementos das posições i e j
            swap(arr[i], arr[j]);
            // Observação: nem sempre o if vai ser disparado, só quando: ao percorrer o vetor, encontramos um elemento menor que o pivô
            // Um exemplo é i=-1 e j=3, ou seja, swap(i, j)
        }
    }

    // Ao encerrar o for, trocamos a posição do pivô para o meio
    swap(arr[i + 1], arr[high]);
    // Ficando os elementos menores que ele à esquerda e os maiores à direita
    return i + 1;
    // Retornamos i+1 com o intuito de, quando for fazer o partition novamente, ignorarmos o pivô
}

// Metodo quickSort que recebe um vetor, o menor e o maior index
void quickSort(vector<int>& arr, int low, int high) {

    // Verificação para impedir que o código quebre
    if (low < high) {

        // Guarda o index do pivô após executar o metodo partition
        int pi = partition(arr, low, high);

        // Realiza o quick sort à esquerda do pivô
        quickSort(arr, low, pi - 1);
        // Realiza o quick sort à direita do pivô
        quickSort(arr, pi + 1, high);
    }
}

//Exemplo
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}