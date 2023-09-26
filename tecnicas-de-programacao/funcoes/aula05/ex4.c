/*4) Escreva um procedimento que receba três vetores de tamanho N por parâmetro. O terceiro vetor deve receber a soma dos dois primeiros.
*/

#include <stdio.h>

void somar(int vetor1[], int vetor2[], int resultado[], int N){
    for (int i = 0; i < N; i++){
        resultado[i] = vetor1[i] + vetor2[i];
    }
}

int main(){
    int N;

    printf("Digite o tamanho dos vetores: ");
    scanf("%i", &N);

    int vetor1[N], vetor2[N], resultado[N];

    printf("Digite os elementos do primeiro vetor:\n");
    for(int i = 0; i < N; i++){
        scanf("%i", &vetor1[i]);
    }

    printf("Digite os elementos do segundo vetor:\n");
    for(int i = 0; i < N; i++){
        scanf("%i", &vetor2[i]);
    }

    somar(vetor1, vetor2, resultado, N);

    printf("Resultado da soma dos vetores:\n");
    for(int i = 0; i < N; i++){
        printf("%i ", resultado[i]);
    }
    printf("\n");

    return 0;
}
