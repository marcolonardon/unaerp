#include <iostream>
using namespace std;

void imprimePai(int arr[], int size, int x) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << x << " nao existe na arvore." << endl;
        return;
    }

    if (index == 0) {
        cout << x << " eh a raiz e nao tem pai." << endl;
        return;
    }

    int parentIndex = (index - 1) / 2;
    cout << "Pai de " << x << ": " << arr[parentIndex] << endl;
}

void imprimeFilhos(int arr[], int size, int x) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << x << " nao existe na arvore." << endl;
        return;
    }

    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    cout << "Filhos de " << x << ": ";
    bool hasChildren = false;

    if (leftChildIndex < size) {
        cout << arr[leftChildIndex] << " ";
        hasChildren = true;
    }
    if (rightChildIndex < size) {
        cout << arr[rightChildIndex] << " ";
        hasChildren = true;
    }

    if (!hasChildren) {
        cout << "Nenhum (eh uma folha ou nao tem filhos no array).";
    }

    cout << endl;
}

void menu() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int opcao;
    int valor;

    do {
        cout << "Menu:\n";
        cout << "1 - Encontrar pai de um no\n";
        cout << "2 - Encontrar filhos de um no\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor do no para encontrar o pai: ";
                cin >> valor;
                imprimePai(arr, size, valor);
                break;
            case 2:
                cout << "Digite o valor do no para encontrar os filhos: ";
                cin >> valor;
                imprimeFilhos(arr, size, valor);
                break;
            case 3:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opcao inválida. Tente novamente.\n";
        }

        cout << endl;
    } while (opcao != 3);
}

int main() {
    menu(); 
    return 0;
}
