/*12) Escreva uma função que receba por parâmetro uma martriz MxM e retorne a soma de seus elementos.*/
#include <stdio.h>

#define M 3

int somarElementosMatriz(int matriz[M][M]){
    int soma = 0;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            soma += matriz[i][j]; 
        }
    }

    return soma;
}

void menu(){
    int matriz[M][M];

    printf("Digite os elementos da matriz %ix%i:\n", M, M);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            scanf("%i", &matriz[i][j]);
        }
    }

    int resultado = somarElementosMatriz(matriz);

    printf("A soma de todos os elementos da matriz é: %i\n", resultado);
}

int main(){
    menu();

    return 0;
}
