/*Procedimento que troque o sinal de um número.*/

#include <stdio.h>
#include <stdlib.h>

void sinal(int& valor){
    valor *= -1; 
}


int main(){
    int valor;
    printf("Insira o valor a ter o sinal alterado: ");
    scanf("%i", &valor);

    sinal(valor);

    printf("\nValor alterado: %i\n\n", valor);
}