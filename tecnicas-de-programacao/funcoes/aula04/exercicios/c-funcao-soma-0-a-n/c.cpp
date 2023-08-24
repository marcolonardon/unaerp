/*c) Escreva uma função que receba um número inteiro positivo e retorne o somatório dos números entre 0 e
o número passado. Exemplo: Caso o parametro seja 3, o resultado deverá ser a soma de 0 + 1+ 2 +3 = 6.*/

#include <stdio.h>
#include <stdlib.h>

int soma(int n){
    int result = 0;
    for(int i = 0; i < n+1; i++){
        result += i;
    }
    
    return result;
}

int main(){
    int valor;
    printf("Insira um valor inteiro e positivo: ");
    scanf("%i", &valor);

    printf("\n\nResultado da soma de 0 a %i = %i\n\n", valor, soma(valor));
}