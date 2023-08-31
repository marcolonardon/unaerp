/*Algoritmo para ler o salario de uma pessoa e mostrar se havera ou nao desconto de imposto de renda
Nova tabela de IR:
Ate 2.112,00 isento*/

#include <stdio.h>
#include <stdlib.h>


void calculo(float x){
	if(x > 2112){
		printf("\nPagara IR.\n\n");
	}else{
		printf("\nIsento de IR.\n\n");
	}
}

void menu(){
	float salario;
	printf("Informe seu salario: ");
	scanf("%f", &salario);
	calculo(salario);
}

main(){
	menu();
}
