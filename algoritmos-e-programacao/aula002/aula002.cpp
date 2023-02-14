//calcular mdeia final
//M= pParcial * 0.4 + pFinal * 0.6

#include <stdio.h>
#include <stdlib.h>

float media, pParcial, pFinal;
main(){
	printf("Insira a nota da prova parcial: ");
	scanf("%f", &pParcial);
	printf("Insira a nota da prova final: ");
	scanf("%f", &pFinal);
	
	media = pParcial * 0.4 + pFinal * 0.6;
	
	printf("\nA meida final e: %.2f\n\n", media);
	
	
	system("pause");
}
