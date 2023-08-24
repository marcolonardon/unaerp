/*f) Escreva uma função que receba um valor de um produto e retorne o valor com cálculo do desconto
seguindo as seguintes regras: a) valor entre 0 e 1000,00 5%; b) valor entre 1000,01 e 2000,00, 10%; c)
acima de 2000,00, 15%.*/

#include <stdio.h>
#include <stdlib.h>

float desconto(float valor){
    float final = valor;

    if(valor > 2000.0){
        final -= valor * 0.15; 
    }else if(valor >= 1000.01){
        final -= valor * 0.1; 
    }else{
        final -= valor * 0.05; 
    }

    return final;

}

int main(){
    float valor;

    printf("\nInsira o preco do produto: ");
    scanf("%f", &valor);

    printf("\nValor com desconto: R$ %.2f\n\n", desconto(valor));
}