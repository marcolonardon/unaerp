/*b) Crie uma função sem retorno que receba 3 parâmetros inteiros positivos, sendo os dois primeiros por valor e o
terceiro por referência. A variável referenciada deverá receber o maior valor dentre as duas primeiras, sendo que
receberá zero caso os valores sejam iguais, ou algum deles sejam negativos.*/

#include <stdio.h>
#include <stdlib.h>

int funcao(int by_val1, int by_val2, int& by_ref){
    if(by_val1 < 0 || by_val2 < 0 || by_val1 == by_val2){
        by_ref = 0;
    }else if(by_val1 > by_val2){
        by_ref = by_val1;
    }else{
        by_ref = by_val2;
    }
}

int main(){
    int valores[3];
    for(int i = 0; i < 3; i++){
        printf("\nInsira o valor %i: ", i+1);
        scanf("%i", &valores[i]);
    }

    printf("\n\nValor inicial: %i\n", valores[2]);

    funcao(valores[0], valores[1], valores[2]);

    printf("\n\nValor passado por referencia: %i\n\n", valores[2]);

    

}