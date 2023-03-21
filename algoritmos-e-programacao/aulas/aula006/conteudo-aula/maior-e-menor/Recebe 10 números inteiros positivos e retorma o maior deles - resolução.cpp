/*Algoritmo para receber 10 n�meros inteiros positivos e 
  retornar qual � o maior e o menor n�mero informado.*/
  
#include <stdio.h>
#include <stdlib.h>

main()
{
	int i, n, maior, menor;
	printf("Digite o numero 1: ");
	scanf("%d", &n);
	maior = n;
	menor = n;

	for(i=2; i<=10; i++)                 
	{
	    printf("Digite o numero %d: ", i);
	    scanf("%d", &n);
	    
	    if (n > maior)
	      maior = n;
		
		if(n < menor)
			menor = n;	   
	}
	printf ("\nO maior numero e: %d\nO menor numero e: %d\n\n", maior, menor);
	system("pause");	
}
