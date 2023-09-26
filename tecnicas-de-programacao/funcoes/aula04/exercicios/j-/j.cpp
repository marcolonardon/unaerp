/*j) Crie um procedimento que imprima o conteúdo de um vetor de inteiros de qualquer tamanho.*/

#include <stdlib.h>
#include <stdio.h>

void imprimir(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void menu(){
	int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    imprimir(vetor, tamanho);
}

int main() {
	menu();

}
