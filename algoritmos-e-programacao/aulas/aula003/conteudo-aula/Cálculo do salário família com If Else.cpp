/*Calcular o valor do sal�rio fam�lia que um colaborador dever�
receber. Para o pagamento do sal�rio fam�lia tem-se: quem recebe
sal�rio at� R$ 806,80 receber� R$ 41,37 por filho e quem recebe  
acima de R$ 806,80 receber� R$ 29,16 por filho */

//declara��o das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//declara��o das vari�veis
float salario, sl_familia;
int qtd_filhos;

//declara��o da fun��o principal
main()
{
	//entrada de dados
	printf("Informe o valor do salario");
	scanf("%f", &salario);
	printf("Informe qtd de filhos");
	scanf("%i", &qtd_filhos);
	
	//c�lculo do valor do sal�rio fam�lia
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
