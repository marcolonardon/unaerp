/*calcular o valor do salario familia que um colaborador devera receber;
 para o pagamento do salario familia tem-se :
 quem recebe salario ate R$ 806,80 recebera 41,37 por filho e quem recebe acima de 806,8 recebera 29,16 por filho.
 o algoritmo devera ler o salario do colaborador, o numero de filhos e imprimir o salario familia*/
 
 #include <stdio.h>
 #include <stdlib.h>
 
 int filhos;
 float salario, sfamilia;
 main(){
 	printf("\nInsira seu salario mensal: ");
 	scanf("%f", &salario);
 	printf("\nInsira a quantidade de filhos: " );
 	scanf("%i", &filhos);
 	
 	if(salario <= 806.8){
 		sfamilia = salario + filhos*41.37;
		printf("\nSalario familia: R$ %.2f\n", sfamilia);		
	}else{
		sfamilia = salario + filhos*29.16;
		printf("Salario familia: R$ %.2f\n", sfamilia); 	
	 }
	 
 	system("pause");
 }
