/*n) Escreva um procedimento que receba dois vetores de tamanhos iguais A e B e que no final do procedimento o
conteúdo dos vetroes estejam trocados*/
#include <stdio.h>
#include <stdlib.h>

void trocarVetores(int vetorA[], int vetorB[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int temp = vetorA[i];
        vetorA[i] = vetorB[i];
        vetorB[i] = temp;
    }
}

void menu(){
	 int vetorA[] = {1, 2, 3, 4, 5};
    int vetorB[] = {6, 7, 8, 9, 10};
    int tamanho = sizeof(vetorA) / sizeof(vetorA[0]);

    printf("Vetor A antes da troca: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetorA[i]);
    }
    printf("\n");

    printf("Vetor B antes da troca: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetorB[i]);
    }
    printf("\n");

    trocarVetores(vetorA, vetorB, tamanho);

    printf("Vetor A depois da troca: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetorA[i]);
    }
    printf("\n");

    printf("Vetor B depois da troca: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetorB[i]);
    }
    printf("\n");
}

int main() {
   menu();
}
