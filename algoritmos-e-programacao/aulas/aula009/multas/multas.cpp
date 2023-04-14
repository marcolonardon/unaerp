/*Ler multas por código
0 - leve = 2 pontos]
1 - moderada = 3 pontos
2 - grave = 5 pontos
3 - gravíssima = 10 pontos
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char cond;
int codigo, pontos, soma, quantidade=0;
main(){
	printf("Ler multas(S/N)?");
	cond = getche ();
	
	while(cond=='s' || cond=='S'){
		quantidade++;
		printf("\nInsira o codigo da multa: ");
		scanf("%i", &codigo);
		switch (codigo){
			case 0:
				pontos=2;
				break;
			case 1:
				pontos=3;
				break;
			case 2:
				pontos=5;
				break;
			case 3:
				pontos=10;
				break;	
			default:
				quantidade--;
		}
		soma+=pontos;
		
		printf("Pontos da multa: %i\n", pontos);
		
		if(quantidade>1){
			printf("Quantidade de multas: %i\n", quantidade);
			printf("Soma: %i\n", soma);
		}
		
		printf("\nLer outra multa(S/N)?");
		cond = getche ();
	}
	printf("\nSistema finalizado.\n\n\n");
	
	system("pause");
}