/*5) Escreva um procedimento que receba dois vetores de tamanho N por parâmetro. Troque o conteúdo entre eles.*/
#include <stdio.h>

void trocar(int vetor1[], int vetor2[], int N){
    for(int i = 0; i < N; i++){
        int temp = vetor1[i];
        vetor1[i] = vetor2[i];
        vetor2[i] = temp;
    }
}

void menu(){
     int N;

    printf("Digite o tamanho dos vetores: ");
    scanf("%i", &N);

    int vetor1[N], vetor2[N];

    printf("Digite os elementos do primeiro vetor:\n");
    for(int i = 0; i < N; i++){
        scanf("%i", &vetor1[i]);
    }

    printf("Digite os elementos do segundo vetor:\n");
    for(int i = 0; i < N; i++){
        scanf("%i", &vetor2[i]);
    }

    trocar(vetor1, vetor2, N);

    printf("Conteúdo dos vetores após a troca:\n");
    printf("Primeiro vetor: ");
    for(int i = 0; i < N; i++){
        printf("%i ", vetor1[i]);
    }
    printf("\nSegundo vetor: ");
    for(int i = 0; i < N; i++){
        printf("%i ", vetor2[i]);
    }
    printf("\n");
}

int main(){
    menu();

    return 0;
}

