#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

struct No* tabela[TAMANHO_TABELA];


int hash(int x) {
    return x % TAMANHO_TABELA;
}

void iniciarTabela(){
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela[i] = NULL;
    }
}

void adicionar(int valor) {
    int posicao = hash(valor);

    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->valor = valor;
    novoNo->proximoNo = NULL;

    if (tabela[posicao] == NULL) {
        tabela[posicao] = novoNo;
    }else {
        struct No* atual = tabela[posicao];
        while (atual->proximoNo != NULL) {
            atual = atual->proximoNo;
        }
        atual->proximoNo = novoNo;
    }

    printf("Valor %d adicionado na posicao %d.\n", valor, posicao);
}

void buscar(int valor) {
    int posicao = hash(valor);
    struct No* atual = tabela[posicao];
    
    while (atual != NULL) {
        if (atual->valor == valor) {
            printf("Valor %d encontrado na posicao %d.\n", valor, posicao);
            return;
        }
        atual = atual->proximoNo;
    }
    
    printf("Valor %d nao encontrado.\n", valor);
}

void imprimirTabela() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        printf("Posicao %d: ", i);
        struct No* atual = tabela[i];
        while (atual != NULL) {
            printf("%d -> ", atual->valor);
            atual = atual->proximoNo;
        }
        printf("NULL\n");
    }
}
