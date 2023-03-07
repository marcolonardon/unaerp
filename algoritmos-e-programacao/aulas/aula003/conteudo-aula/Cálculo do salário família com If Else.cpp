/*Calcular o valor do salário família que um colaborador deverá
receber. Para o pagamento do salário família tem-se: quem recebe
salário até R$ 806,80 receberá R$ 41,37 por filho e quem recebe  
acima de R$ 806,80 receberá R$ 29,16 por filho */

//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declaração das variáveis
float salario, sl_familia;
int qtd_filhos;

//declaração da função principal
main()
{
	//entrada de dados
	printf("Informe o valor do salario");
	scanf("%f", &salario);
	printf("Informe qtd de filhos");
	scanf("%i", &qtd_filhos);
	
	//cálculo do valor do salário família
	if(salario <= 806.80)
	{
		sl_familia = qtd_filhos * 41.37;
		printf("\nTotal salario familia = R$ %.2f", sl_familia);
	}
	else
	{
		sl_familia = qtd_filhos * 29.16;
		printf("\nTotal salario familia = R$ %.2f", sl_familia);
	}
	
	system("pause");
}
