/* Algoritmo para ler o tempo, em segundos, que um nadador percorre 100 metros
   e calcular o tempo em que ele percorre 100 jardas.
   1 j = 0,9144 m */
   
#include<stdio.h>
#include<stdlib.h>

float t100m, t100j ;

main()
{
	printf("Informe o tempo para 100 metros (s): ") ;
	scanf("%f", &t100m) ;
	
	t100j = t100m *0.9144 ;
	
	printf("\nO tempo para 100 jardas e %.2f\n\n", t100j);
	
	system("pause") ;
}
