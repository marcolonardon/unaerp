// Algoritmo para determinar o maior de dois números

# include <stdlib.h>
# include <stdio.h>

int num1, num2, maior, iguais = 0;

main()
{
	// 1. ler dados
	printf("Digite um numero inteiro: ") ;
	scanf("%i", &num1) ;
	printf("Digite outro numero inteiro: ") ;
	scanf("%i", &num2) ;
	
	// 2. comparar os dois números
	if(num1 > num2)	
	{ 
		maior = num1 ;
    }
	else
	{
		if(num2 > num1)
			maior = num2 ;
		else
			iguais = 1 ;
	}
	
	// 3. Imprimir resultado
	if(iguais == 0)
		printf("O maior numero e: %i\n\n", maior) ;
	else
		printf("Os valores sao iguais\n\n") ;
		
	// 4. terminar
	system("pause")	;
	
}


