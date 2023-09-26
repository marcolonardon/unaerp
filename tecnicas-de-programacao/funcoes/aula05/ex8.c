/*8).*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherMatrizAleatoria(int **matriz, int M, int N){
    // Inicialize a semente do gerador de números aleatórios
    srand(time(NULL));

    // Preencha a matriz com números aleatórios limitados até 100
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 101; // Gere números entre 0 e 100
        }
    }
}

void menu(){
    int M, N;

    printf("Digite o número de linhas (M) da matriz: ");
    scanf("%i", &M);

    printf("Digite o número de colunas (N) da matriz: ");
    scanf("%i", &N);

    int **matriz = (int **)malloc(M * sizeof(int *));
    for (int i = 0; i < M; i++) {
        matriz[i] = (int *)malloc(N * sizeof(int));
    }

    preencherMatrizAleatoria(matriz, M, N);

    printf("Matriz preenchida com números aleatórios até 100:\n");
    for(int i = 0; i < M; i++){
        for (int j = 0; j < N; j++) {
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < M; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(){
    menu();

    return 0;
}


