/*Procedimento que modifica o valor de um número para seu quadrado.*/

#include <stdio.h>
#include <stdlib.h>

float valor;

void quadrado(float *valor){
    *valor *= *valor;
}

void imprimir(){
    printf("\nO quadrado do valor: %.2f\n\n", valor);
}

void menu(){
    printf("\nInsira o valor a ser modificado: ");
    scanf("%f",&valor);
    quadrado(&valor);
    imprimir();
}

int main(){
    menu();
}