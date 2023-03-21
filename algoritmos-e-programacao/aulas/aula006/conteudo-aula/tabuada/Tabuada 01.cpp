// Impressão de Tabuada

#include<stdio.h>
#include<stdlib.h>

int i, n, r ;

main()
{
	printf("Forneca o numero da tabuada: ");
	scanf("%i",&n); 
	
	printf("\n");
	for(i=1;i<=10;i++)
	{
		r = i * n ;
		printf("%i x %2.i = %3.i\n", n, i, r);
	}
	printf("\n");
	system("pause");	
}




