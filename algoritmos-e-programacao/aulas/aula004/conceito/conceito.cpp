/*Dterminar e imprimir a média e o conceito do aluno com base na média:
Média = Parcial * 0.4 + Final * 0.6 (obs: notas de 0 a 100)
Conceitos:
		 A: 80 a 100
		 B: 70 a 79
		 C: 60 a 69
		 D: 50 a 59
		 E: < 50*/ 
#include <stdio.h>
#include <stdlib.h>

int pParcial, pFinal, media;
main(){
	printf("Insira a nota da prova parcial(0 a 100): ");
	scanf("%i", &pParcial);
	printf("\nInsira a nota da prova final(0 a 100): ");
	scanf("%i", &pFinal);
	
	media = (pParcial*4 + pFinal*6) / 10;
	printf("\nMedia: %i\n", media);
	
	if(media < 50){
		printf("Conceito: E\n\n");
	}else if(media < 60){
		printf("Conceito: D\n\n");
	}else if(media < 70){
		printf("Conceito: C\n\n");
	}else if(media < 80){
		printf("Conceito: B\n\n");
	}else{
		printf("Conceito: A\n\n");
	}
	
	system("pause");
}
