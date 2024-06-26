#include <iostream>
#include <vector>

using namespace std;

// Função para busca binária
int buscaBinaria(vector<int>& arr, int x) {
    int esquerda = 0;
    int direita = arr.size() - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        // Se o elemento está no meio, retorna o índice
        if (arr[meio] == x) {
            return meio;
        }
        // Se o elemento é maior, ignora a metade esquerda
        if (arr[meio] < x) {
            esquerda = meio + 1;
        }
        // Se o elemento é menor, ignora a metade direita
        else {
            direita = meio - 1;
        }
    }
    // Se o elemento não foi encontrado, retorna -1
    return -1;
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int resultado = buscaBinaria(arr, x);
    (resultado == -1) ? cout << "Elemento não esta presente no vetor\n"
                       : cout << "Elemento encontrado no indice " << resultado << "\n";
    return 0;
}