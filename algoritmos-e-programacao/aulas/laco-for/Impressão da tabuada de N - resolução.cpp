// Algoritmo para imprimir a tabuada de um número N lido

#include <stdio.h>
#include <stdlib.h>

int i, n, resultado	;
	
main()
{
	printf("Entre um numero de 1 a 10: ") ;
	scanf("%i", &n) ;
	
	for(i=1; i<=10; i++)
	{
		resultado = i * n ;
		printf("%i * %i = %2.i\n", i, n, resultado)	;		
	}
	
	system("pause");
}










