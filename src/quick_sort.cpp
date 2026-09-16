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

// Metodo partitionRandom que escolhe um pivô aleatório em vez de sempre usar o último elemento
// Recebe o vetor arr, o index low (menor) e o high (maior)
int partitionRandom(vector<int>& arr, int low, int high) {

    // Sorteia um index qualquer dentro do intervalo [low, high]
    // O % (high - low + 1) garante que o número caia dentro do tamanho do intervalo
    // E o + low desloca esse número pra começar em low, e não em 0
    int randomIndex = low + rand() % (high - low + 1);

    // Troca o elemento sorteado com o último elemento do intervalo
    // Isso é necessário porque o metodo partition tradicional sempre espera o pivô em arr[high]
    swap(arr[randomIndex], arr[high]);

    // A partir daqui, a lógica é exatamente igual ao partition tradicional
    // Só que agora quem está em arr[high] é o elemento sorteado, e não o último original
    return partition(arr, low, high);
}

// Metodo medianOfThree que escolhe o pivô como o valor mediano entre o primeiro, o meio e o último elemento
// Recebe o vetor arr, o index low (menor) e o high (maior)
int medianOfThree(vector<int>& arr, int low, int high) {

    // Calcula o index do meio do intervalo
    // Usamos low + (high - low) / 2 em vez de (low + high) / 2 pra evitar overflow em vetores muito grandes
    // Ex: 0 (3-0) / 3 = 1
    int mid = low + (high - low) / 2;

    // As três comparações abaixo colocam arr[low], arr[mid] e arr[high] em ordem crescente entre si
    // Observação: isso NÃO ordena o vetor inteiro, somente as três posições específicas

    // Se o elemento do meio for menor que o do início, troca os dois
    if (arr[mid] < arr[low]) swap(arr[mid], arr[low]);

    // Se o elemento do fim for menor que o do início, troca os dois
    if (arr[high] < arr[low]) swap(arr[high], arr[low]);

    // Se o elemento do fim for menor que o do meio, troca os dois
    if (arr[high] < arr[mid]) swap(arr[high], arr[mid]);

    // Depois dessas três comparações, temos garantido que: arr[low] <= arr[mid] <= arr[high]
    // Ou seja, arr[mid] é o valor mediano dos três, que é justamente o pivô que queremos usar

    // Troca o mediano (que está em arr[mid]) para arr[high]
    // Necessário porque o metodo partition tradicional sempre espera o pivô na última posição
    swap(arr[mid], arr[high]);

    // A partir daqui, a lógica é exatamente igual ao partition tradicional
    return partition(arr, low, high);
}

// Metodo quickSort que recebe um vetor, o menor e o maior index
// Nesse caso o Quick puxa o metodo partition, mas poderia ser os dois metodos acima
void quickSort(vector<int>& arr, int low, int high) {

    
    // Verificação para impedir que o código quebre
    if (low < high) {

        // Guarda o index do pivô após executar o metodo partition
        int pi = medianOfThree(arr, low, high);

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