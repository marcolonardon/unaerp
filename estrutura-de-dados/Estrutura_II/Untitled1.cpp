#include <stdlib.h>
#include <stdio.h>

typedef struct no No;
typedef struct no {
    int dado;
    No *esquerdo, *direito;
}No;

typedef struct arvore {
    No* raiz;
} Arvore;

No* CriarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro de alocação de memória\n");
        return NULL;
    }
    novoNo->dado = dado;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    return novoNo;
}

Arvore* CriarArvore(int raiz) {
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    if (!arvore) {
        printf("Erro de alocação de memória\n");
        return NULL;
    }
    
    arvore->raiz = CriarNo(raiz);
    return arvore;
}

void Inserir(Arvore* arvore, int valor) {
	if(arvore->raiz->dado <= valor){
		printf("Entrou para esquerda com valor %i\n", valor);
		arvore->raiz->esquerdo = CriarNo(valor);
	}
    else{
    	printf("Entrou para direita com valor %i\n", valor);
    	arvore->raiz->direito = CriarNo(valor);
	}
    	
}

int Buscar(Arvore* arvore, int valor){
    // completar
    return 0;
}

void PrintPreOrderRecursao(No* no) {
    if(no == NULL) {
        return;
    }
    
    printf("%d ", no->dado);
    PrintPreOrderRecursao(no->esquerdo);
    PrintPreOrderRecursao(no->direito);
}

void PrintPreOrder(Arvore* arvore){
    PrintPreOrderRecursao(arvore->raiz);
    printf("\n");
}

void PrintInOrderRecursao(No* no) {
    if(no == NULL) {
        return;
    }
    
    PrintInOrderRecursao(no->esquerdo);
    printf("%d ", no->dado);
    PrintInOrderRecursao(no->direito);
}

void PrintInOrder(Arvore* arvore){
    PrintInOrderRecursao(arvore->raiz);
    printf("\n");
}

void PrintPostOrderRecursao(No* no) {
    if(no == NULL) {
        return;
    }
    
    PrintPostOrderRecursao(no->esquerdo);
    PrintPostOrderRecursao(no->direito);
    printf("%d ", no->dado);
}

void PrintPostOrder(Arvore* arvore){
    PrintPostOrderRecursao(arvore->raiz);
    printf("\n");
}

void LiberaMemoriaNo(No* no) {
    if(no == NULL) {
        return;
    }
    
    LiberaMemoriaNo(no->esquerdo);
    LiberaMemoriaNo(no->direito);
    free(no);
}

void LiberarMemoria(Arvore* arvore){
    LiberaMemoriaNo(arvore->raiz);
    free(arvore);
}

int main() {
    Arvore* minhaArvore = CriarArvore(10);
    Inserir(minhaArvore, 5);
    Inserir(minhaArvore, 15);
    Inserir(minhaArvore, 3);
    Inserir(minhaArvore, 7);

    printf("PreOrder: ");
    PrintPreOrder(minhaArvore);

    printf("InOrder: ");
    PrintInOrder(minhaArvore);

    printf("PostOrder: ");
    PrintPostOrder(minhaArvore);

    if (Buscar(minhaArvore, 7)) {
        printf("Valor 7 encontrado na arvore!\n");
    } else {
        printf("Valor 7 nao encontrado na arvore!\n");
    }

    LiberarMemoria(minhaArvore);
    return 0;
}
