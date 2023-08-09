/*Função que retorna o máximo entre dois números.*/

#include <stdio.h>
#include <stdlib.h>

bool flag=0;

int maior(int a, int b){
    if(a==b){
        printf("\nOs valores sao iguais.\n");
        return 0;
    }else{
        flag=1;
        return (a > b) ? a : b;
    }
    
}

int main(){
    int a, b, maximo;
    printf("\nInsira dois valores inteiros diferentes: ");
    scanf("%i %i",&a, &b);

    maximo = maior(a,b);
    
    if(flag){
        printf("\nO maior valor e %i\n", maximo);
    }
}