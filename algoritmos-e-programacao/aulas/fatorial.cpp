/*Algoritmo para calcular e imprimir o fatorial de um numero n(inteiro e positivo, podendo ser 0)*/

#include <stdio.h>
#include <stdlib.h>

int n, i, fat=1;
main(){
	printf("Insira um numero a ser fatorado: ");
	scanf("%i", &n);
	
	if(n >= 0){
	
	for(i=n; i > 0; i--)
		fat = fat * i;
		
		printf("%i! = %i\n\n", n, fat);
	}else
		printf("\nSomente valores maiores ou iguaias a zero sao aceitos.\n\n");
	
	system("pause");
}
