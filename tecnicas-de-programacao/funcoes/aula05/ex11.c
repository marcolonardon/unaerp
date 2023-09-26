//11) Escreva um procedimento que receba por parâmetro uma martriz MxM e troque as diagonais da mesma. A principal passa a conter os valores da secundária e a secundária passa a conter os valores da primária.
#include <stdio.h>

#define M 3 

void trocarDiagonais(int matriz[M][M]){
    for (int i = 0; i < M; i++) {
        int temp = matriz[i][i]; 
        matriz[i][i] = matriz[i][M - 1 - i]; 
        matriz[i][M - 1 - i] = temp; 
    }
}

void imprimirMatriz(int matriz[M][M]){
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            printf("%i\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void menu(){
        int matriz[M][M];

    printf("Digite os elementos da matriz %ix%i:\n", M, M);

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++){
            scanf("%i", &matriz[i][j]);
        }
    }

    printf("Matriz original:\n");
    imprimirMatriz(matriz);

    trocarDiagonais(matriz);

    printf("Matriz com diagonais trocadas:\n");
    imprimirMatriz(matriz);
}

int main(){
    menu();

    return 0;
}
