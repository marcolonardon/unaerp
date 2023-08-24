/*a) Crie uma função que receba dois valores referentes ao preço de uma mercadoria e a porcentagem para o
desconto. Retorne o novo preço com o desconto calculado.*/

#include <stdio.h>
#include <stdlib.h>

float desconto(float valor, float porcentagem){
    porcentagem = porcentagem / 100;
    valor -= valor * porcentagem;
    return valor;
}

int main(){
    float valor, porcentagem;
    printf("Insira o valor da mercadoria: R$ ");
    scanf("%f", &valor);
    printf("\nInsira a porcentagem de desconto:  ");
    scanf("%f", &porcentagem);

    printf("\nPocentagem de desconto: %.2f %%\nValor final: R$ %.2f\n\n",porcentagem, desconto(valor, porcentagem));

}