// Média Harmônica com 5 números inteiros e positivos
#include <stdlib.h>
#include <stdio.h>

int i, vetor[5];
float somatoria=0.0, media;
main(){
	for(i=0; i<5; i++){
		printf("Informe o numero %i: ", i+1);
		scanf("%i", &vetor[i]);
	}
	
	for(i=0; i<5; i++){
		somatoria = somatoria + 1.0 / vetor[i];
	}
	
	media = 5 / somatoria;
	
	printf("A Media Harmonica e %.3f\n\n", media);
	
	
	
	
	
	system("pause");
}


