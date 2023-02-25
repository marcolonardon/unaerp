//cometarios em uma linha
/* comentarios em
diversas linhas*/

#include <stdio.h>//entrada e saida de dados
#include <stdlib.h>//funcoes mais utilizadas


//soma de numeros
int res, n1, n2, pergunta;

main(){
	printf("insira um valor inteiro: ");
	scanf("%i", &n1);
	printf("insira outro valor inteiro: ");
	scanf("%i", &n2);
	
	
	printf("1 para multiplicar ou 2 para somar ");
	scanf("%i", &pergunta);
	
	if(pergunta == 1){
		res = n1 * n2;
		printf("\n\n o resultado da multiplicacao e: %i\n\n", res);
	}else{
		res = n1 + n2;
		printf("\n\n o resultado da multiplicacao e: %i\n\n", res);
	}
	
	
	system("pause"); //sempre usar o system("pause")
}


