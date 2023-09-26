/*7) Faça um procedimento que receba um vetor de tamanho N e o preencha com números aleatórios.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetorAleatorio(int vetor[], int N){
    srand(time(NULL));

    for(int i = 0; i < N; i++){
        vetor[i] = rand() % 101;
    }
}

void menu(){
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &n);

    int vetor[n];

    preencherVetorAleatorio(vetor, n);

    printf("Vetor preenchido com números aleatórios:\n");
    for (int i = 0; i < n; i++) {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

int main(){
    menu();

    return 0;
}
