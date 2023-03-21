/*Algoritmo para receber 10 n�meros inteiros positivos e 
  retornar qual � o maior n�mero informado.*/
  
#include <stdio.h>
#include <stdlib.h>

main()
{
	int i, n, maior;
	maior = 0 ;
	
	for(i=1; i<=10; i++)                 
	{
	    printf("Digite o numero %d: ", i);
	    scanf("%d", &n);
	    
	    if (n > maior)
	      maior = n;	   
	}
	printf ("\no maior numero e %d\n\n", maior);
	system("pause");	
}
