/*
int x[5]; // declara��o de um vetor - guarda 5 n�meros inteiros
int m[5][5]; // declara��o de uma matriz - guarda 25 n�meros inteiros

string - tem \0 no final, cadeia de caracteres n�o tem
	

algoritmo para gerar 6 n�meros aleat�rios (armazenar em um vetor), ler 3 n�meros e
verificar quantos n�meros lidos s�o iguais aos n�meros sorteados
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


