#include <stdlib.h>
#include <stdio.h>

typedef struct no No;
typedef struct no {
    int dado;
    No* esquerdo, direito;
}No;

typedef struct arvore {
    No* raiz;
} Arvore;

typedef struct arvore {
	No* raiz;
} Arvore;

Arvore* CriarArvore(int arr[], int size){
	Arvore* nova_arvore = malloc(sizeof(Arvore));
	// percorrer o array e popular árvore
	for(int i=0; i<size; i++){
		nova_arvore->raiz;
	}
	return nova_arvore;

}

void PrintPreOrder(Arvore* arvore){

}
void PrintInOrder(Arvore* arvore){

}
void PrintPosOrder(Arvore* arvore){

}