/*h) Crie um procedimento que receba 3 parâmetros de ponto flutante positivos, sendo os dois primeiros por valor
e o terceiro por referência. A primeira variável se refere ao salario atual, a segunda a porcentagem de reajuste e
por fim a terceira receberá o novo valor reajustado.*/

#include <stdlib.h>
#include <stdio.h>


void valores(float salario, float reajuste, float& novo){
	novo = salario + (reajuste/100)*salario;
}

void menu(){
	float salario, per, novo;
	printf("Insira seu salario atual: R$ ");
	scanf("%f", &salario);
	printf("\nInsira a porcentagem de reajuste: ");
	scanf("%f", &per);
	valores(salario, per, novo);
	
	printf("\n\nSeu novo salario sera R$ %.2f\n\n", novo);
	
}

int main(){
	menu();
}