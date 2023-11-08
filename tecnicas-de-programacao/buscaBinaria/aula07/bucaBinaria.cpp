#include <stdio.h>
#include <stdlib.h>

#define TAM 2

typedef struct{
	int ra;
	char nome[20];
}aluno;

aluno novoAluno[TAM];

void preencher(){
	for(int i=0; i<TAM; i++){
		novoAluno[i].ra = (i+1)+100;
		printf("Informe o nome do aluno %i: ", (i+1)+100);
		scanf("%s[^\n]", &novoAluno[i].nome);
		
	}
}

void ordenar(){
	
}

int buscaBinaria(aluno vetor[], int esq, int dir, int chave){
	while(esq <= dir){
		int meio = esq + (dir-esq)/2;
		if(vetor[meio].ra==chave){
			return meio;
		}
		if(vetor[meio].ra<chave){
			esq = meio+1;
		}else{
			dir = meio-1;
		}
	}
	return -1;
}

void imprimir(){
	for(int i=0; i<TAM; i++){
		printf("\nCodigo: %i", novoAluno[i].ra);
		printf("\nNome: %s\n\n", novoAluno[i].nome);
	}
}

main(){
	int buscar = 101;
	preencher();
	//imprimir();
	if(buscaBinaria(novoAluno,0,TAM,buscar) == -1){
		printf("\n\nAluno nao encontrado\n\n");
	}else{
		printf("\n\nAluno encontrado na posicao %i\n\n", buscaBinaria(novoAluno,0,TAM,buscar));
	}
}