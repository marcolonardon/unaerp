/* Algoritmo para ler temperatura em graus celsius e calcular e imprimir
   a temperatura em graus fahrenheit:
   f = 9/5 C + 32 */
   
#include<stdio.h>
#include<stdlib.h>

float celsius, fahrenheit ;

main()
{
	printf("informe a temperatura em graus celsius: ") ;
	scanf("%f", &celsius) ;
	
	fahrenheit = celsius * 9 / 5 + 32 ;
	
	printf("\nA temperatura em fahrenheit e %.1f\n\n", fahrenheit);
	
	system("pause");
}
   
