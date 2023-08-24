/*d) Escreva um procedimento que exiba na tela a tabuada do número passado por parâmetro.*/

#include <stdio.h>
#include <stdlib.h>

void tabuada(int n){
    int resultado;
    for(int i=1; i<11; i++){
        if(n == 0)
            resultado = 0;
        else
            resultado = i * n;

        printf("\n\t%i  *  %i = %i ",i, n, resultado);
    }
}

int main(){
    int n;
    printf("Insira o numero que deseja a tabuada: ");
    scanf("%i", &n);

    tabuada(n);
}