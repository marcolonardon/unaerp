/*l) Crie um procedimento que receba 3 vetores A, B e C, sendo A e B de tamanhos iguais e C a soma dos
tamanhos de A e B. O procedimento deve armazenar o conteúdo de A na primeira metade de C e o conteúdo de
B, na segunda metade de C. Imprima os 3 vetores.*/

#include <stdio.h>
#include <stdlib.h>

void mist(int a[], int b[], int c[], int tamanhoAB) {
    int i;

    for (i = 0; i < tamanhoAB; i++) {
        c[i] = a[i];
    }

    for (i = 0; i < tamanhoAB; i++) {
        c[i + tamanhoAB] = b[i];
    }
}

void menu(){
	    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int tamanhoAB = sizeof(a) / sizeof(a[0]);
    int tamanhoC = 2 * tamanhoAB;
    int c[tamanhoC];

    mist(a, b, c, tamanhoAB);

    printf("Vetor A: ");
    for (int i = 0; i < tamanhoAB; i++) {
        printf("%i ", a[i]);
    }
    printf("\n");

    printf("Vetor B: ");
    for (int i = 0; i < tamanhoAB; i++) {
        printf("%i ", b[i]);
    }
    printf("\n");

    printf("Vetor C: ");
    for (int i = 0; i < tamanhoC; i++) {
        printf("%i ", c[i]);
    }
    printf("\n");
}

int main() {
	menu();
}
