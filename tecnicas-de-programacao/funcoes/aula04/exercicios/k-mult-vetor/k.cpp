/*k) Crie um procedimento que faça a multiplicação de um escalar qualquer em um vetor de inteiros.*/

#include <stdlib.h>
#include <stdio.h>

void imprimir(int vetor[], int tamanho) {
	int escalar = 3;
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]*escalar);
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