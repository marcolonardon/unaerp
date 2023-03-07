//maior entre três números inteiros não iguais
#include <stdio.h>
#include <stdlib.h>

int n1, n2, n3, maior, menor;
main(){
	
	printf("Entre o N1: ");
	scanf("%i", &n1);
	printf("Entre o N2: ");
	scanf("%i", &n2);
	printf("Entre o N3: ");
	scanf("%i", &n3);
	
	if(n1 > n2){
		if(n1 > n3){
			maior = n1;
			if(n2 > n3){
				menor = n3;
			}else{
				menor = n2;
			}
		}else{
			maior = n3;
			menor = n2;
		}	
	}else{
		if(n1 > n3){
			maior = n2;
			menor = n3;
		}else{
			if(n2 > n3){
				maior = n2;
				menor = n1;
			}else{
				maior = n3;
				menor = n1;
			}
		}
	}
	
	printf("Maior: %i\nMenor: %i", maior, menor);
	
}
