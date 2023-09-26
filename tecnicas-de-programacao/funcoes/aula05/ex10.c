/*10) Escreva dois procedimentos, "d_principal"  e "d_secundaria". Ambos recebem uma matriz MxM por parâmetro e cada procedimento deve colocar na tela
a diagonal a que cada se refere.*/
#include <stdio.h>

#define M 3 // Tamanho da matriz (altere para o tamanho desejado)

void d_principal(int matriz[M][M]){
    printf("Diagonal Principal:\n");
    for (int i = 0; i < M; i++) {
        printf("%i ", matriz[i][i]);
    }
    printf("\n");
}

void d_secundaria(int matriz[M][M]){
    printf("Diagonal Secundaria:\n");
    for (int i = 0; i < M; i++) {
        printf("%i ", matriz[i][M - 1 - i]);
    }
    printf("\n");
}

void menu(){
        int matriz[M][M];

    printf("Digite os elementos da matriz %ix%i:\n", M, M);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%i", &matriz[i][j]);
        }
    }

    d_principal(matriz);
    d_secundaria(matriz);
}

int main(){
    menu();

    return 0;
}
