#include <iostream>
#include <vector>

using namespace std;

/*
    A função mesclar junta duas partes já ordenadas:

    Exemplo:
    parte esquerda: [2, 5, 8]
    parte direita:  [1, 4, 9]

    Resultado:
    [1, 2, 4, 5, 8, 9]
*/
void mesclar(vector<int>& numeros, int inicio, int meio, int fim)
{
    vector<int> temporario;

    int esquerda = inicio;
    int direita = meio + 1;

    // Compara os elementos das duas partes
    while (esquerda <= meio && direita <= fim)
    {
        if (numeros[esquerda] <= numeros[direita])
        {
            temporario.push_back(numeros[esquerda]);
            esquerda++;
        }
        else
        {
            temporario.push_back(numeros[direita]);
            direita++;
        }
    }

    // Adiciona o que sobrou da parte esquerda
    while (esquerda <= meio)
    {
        temporario.push_back(numeros[esquerda]);
        esquerda++;
    }

    // Adiciona o que sobrou da parte direita
    while (direita <= fim)
    {
        temporario.push_back(numeros[direita]);
        direita++;
    }

    // Copia os valores ordenados de volta para o vetor original
    for (int i = 0; i < temporario.size(); i++)
    {
        numeros[inicio + i] = temporario[i];
    }
}

/*
    O Merge Sort funciona assim:

    1. Divide o vetor em duas partes.
    2. Divide cada parte novamente.
    3. Continua dividindo até sobrarem partes com apenas um elemento.
    4. Junta as partes ordenando-as.

    Um único elemento já está ordenado.
*/

void mergeSort(vector<int>& numeros, int inicio, int fim)
{
    // Se caso possui zero ou um elemento (ai já está ordenado), então não precisa fazer nada
    if (inicio >= fim)
    {
        return;
    }

    //calculo para achar o meio do vetor
    //exemplo: meio = 0 + (5 - 0) / 2 = 2
    //{50, 40, 30, (meio), 20, 10, 0}
    int meio = inicio + (fim - inicio) / 2;

    // Ordena a metade esquerda, pois do inicio ao meio é a parte da esquerda
    mergeSort(numeros, inicio, meio);

    // Ordena a metade direita, pois do meio+1 ao fim é a parte da direita
    mergeSort(numeros, meio + 1, fim);

    // Junta as duas metades ordenadas
    mesclar(numeros, inicio, meio, fim);
}

int main()
{
    int tamanho;

    cout << "Digite o tamanho do vetor: ";
    cin >> tamanho;

    if (tamanho <= 0)
    {
        cout << "O tamanho deve ser maior que zero." << endl;
        return 1;
    }

    vector<int> numeros(tamanho);

    cout << "Digite os " << tamanho << " numeros do vetor:" << endl;

    for (int i = 0; i < tamanho; i++)
    {
        cin >> numeros[i];
    }

    mergeSort(numeros, 0, tamanho - 1);

    cout << "Vetor ordenado: ";

    for (int numero : numeros)
    {
        cout << numero << " ";
    }

    cout << endl;

    return 0;
}
