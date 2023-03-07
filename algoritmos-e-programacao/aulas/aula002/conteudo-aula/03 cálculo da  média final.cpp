/* Algoritmo para ler a nota de prova parcial e nota de prova final,
   calcular e imprimir a média final */

#include <stdio.h>
#include <stdlib.h>

float media, parcial, final ;

main()
{
	printf("Entre a nota da prova parcial: ") ;
	scanf("%f", &parcial) ;
	printf("Entre a nota da prova final: ") ;
	scanf("%f", &final) ;
	
	media = parcial * 0.4 + final * 0.6 ;
	
	printf("A media final e %.1f\n\n", media) ;
	
	system("pause");
	
}
