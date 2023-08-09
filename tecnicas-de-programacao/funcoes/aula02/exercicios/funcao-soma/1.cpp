/*Função que recebe dois números inteiros e retorna a soma deles.*/
#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b){
    return a+b;
}

int main(){
    int a, b;
    printf("\nInsira dois valores inteiros: ");
    scanf("%i %i", &a, &b);
    printf("%i + %i = %i", a, b, soma(a, b));
}