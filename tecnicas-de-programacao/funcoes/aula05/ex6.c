/*6) Escreva um procedimento que receba duas matrizes NxN e faça a soma entre elas, salvando em uma terceira matriz de mesmo tamanho.*/

#include <stdio.h>
#include <stdlib.h>

const int TAM = 3;

void soma(int a[TAM][TAM], int b[TAM][TAM]){
    int ab[TAM][TAM];
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            ab[i][j] = a[i][j] + b[i][j];
        }

    }
    
    printf("\nSoma das matrizes:\n");
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            printf(" %i ", ab[i][j]);
        }
        printf("\n");
    }



}
void carregar(int matriz[TAM][TAM]) {
    printf("Digite os elementos da matriz %ix%i:\n", TAM, TAM);

    for (int i=0; i < TAM; i++) {
        for (int j=0; j < TAM; j++) {
            printf("Elemento [%i][%i]: ", i, j);
            scanf("%i", &matriz[i][j]);
        }
    }
}

void menu(){
    int a[TAM][TAM], b[TAM][TAM];
    carregar(a);
    carregar(b);
    soma(a, b);
}

main(){
    menu();
}