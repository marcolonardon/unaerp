/*m) Crie um função que receba como parâmetro um vetor de inteiros de tamanho qualquer e retorne um valor
verdade caso mais de 50% do vetor contenha numeros pares.*/

#include <stdio.h>
#include <stdbool.h>

bool mais(int vetor[], int tamanho) {
    int pares = 0;

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 == 0) {
            pares++;
        }
    }

    return (pares > tamanho / 2);
}

void menu(){
	    int vetor1[] = {2, 4, 6, 7, 8};
    int tamanho1 = sizeof(vetor1) / sizeof(vetor1[0]);

    if (mais(vetor1, tamanho1)) {
        printf("Mais de 50%% dos elementos sao pares no vetor 1.\n");
    } else {
        printf("Menos de 50%% dos elementos sao pares no vetor 1.\n");
    }

    int vetor2[] = {1, 3, 5, 7, 9};
    int tamanho2 = sizeof(vetor2) / sizeof(vetor2[0]);

    if (mais(vetor2, tamanho2)) {
        printf("Mais de 50%% dos elementos sao pares no vetor 2.\n");
    } else {
        printf("Menos de 50%% dos elementos sao pares no vetor 2.\n");
    }

}

int main() {
	menu();
}
