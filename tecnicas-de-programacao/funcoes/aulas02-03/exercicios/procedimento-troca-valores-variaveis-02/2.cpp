/*Procedimento que troca os valores de duas variáveis.*/

#include <stdio.h>
#include <stdlib.h>

int a, b;

void inverter(int *a, int *b){
    int a2 = *a;
    *a = *b;
    *b = a2;
}

void imprimir(){
    printf("\nValores trocados:\nA = %i\nB = %i\n\n", a, b);
}

void inicio(){
    printf("Insira a Variavel A: ");
    scanf("%i", &a);
    printf("Insira a Variavel B: ");
    scanf("%i", &b);

    inverter(&a, &b);
    imprimir();
}

int main(){
    inicio();
}