/*g) Escreva uma função que receba um valor de venda de algum produto e retorne o novo valor com o
cálculo do ICMS (considere 18%).*/

#include <stdio.h>
#include <stdlib.h>

float calculo(float valor){
    return valor *= 0.18;
}

int main(){
    float valor;
    printf("Insira o valor da venda: R$ ");
    scanf("%f", &valor);

    if(valor > 0){
        printf("\nValor da venda: R$ %.2f\nAliquota: 18%%\nValor do ICMS: R$ %.2f\nVenda com ICMS descontado: R$ %.2f\n\n",valor, calculo(valor), valor - calculo(valor));
    }else{
        printf("\nO valor deve ser maior que zero.\n\n");
    }

    
}