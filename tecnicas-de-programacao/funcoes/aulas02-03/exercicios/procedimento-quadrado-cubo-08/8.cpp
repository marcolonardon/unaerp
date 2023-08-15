/*Procedimento que calcula e devolva o quadrado e o cubo de um número.*/

#include <stdio.h>
#include <stdlib.h>
#include <cmath>

void quadrado(float x){
    printf("\n%.2f^2 = %.2f", x, pow(x,2));
}

void cubo(float x){
    printf("\n%.2f^3 = %.2f", x, pow(x,3));
}

int main(){
    float valor;

    printf("\nInsira um valor: ");
    scanf("%f", &valor);

    quadrado(valor);
    cubo(valor);

}