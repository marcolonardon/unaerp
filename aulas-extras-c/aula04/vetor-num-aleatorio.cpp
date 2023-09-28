/*
int x[5]; // declaração de um vetor - guarda 5 números inteiros
int m[5][5]; // declaração de uma matriz - guarda 25 números inteiros

string - tem \0 no final, cadeia de caracteres não tem
	

algoritmo para gerar 6 números aleatórios (armazenar em um vetor), ler 3 números e
verificar quantos números lidos são iguais aos números sorteados
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAM 6

int lidos[3], aleatorio[TAM];

void gerar(){
	srand(time(NULL));
	
	printf("\nNumeros gerados:\n");
	
	for(int i=0; i<TAM; i++){
		aleatorio[i]=rand()%11;
	/*	for(int j=0; j<i; j++){
			while(aleatorio[j]==aleatorio[i]){
				aleatorio[i]=rand()%11;
			}
		}
	*/
		
		printf("%i ", aleatorio[i]);
	}
}

int verificar(){
	int contador=0;
	gerar();
	for(int i=0; i<TAM; i++){
		for(int j=0; j<3; j++){
			if(aleatorio[i]==lidos[j]){
				contador++;
			}
		}
			
	}
	
	return contador;
}


void menu(){

	for(int i=0; i<3; i++){
		printf("Insira o %i numero : ", i+1);
		scanf("%i", &lidos[i]);
	}
	
	printf("\nQuantidade de numeros iguais: %i", verificar());
	
	
}

main(){
	menu();
}


