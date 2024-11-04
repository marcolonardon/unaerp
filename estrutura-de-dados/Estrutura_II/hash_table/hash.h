#ifndef HASH_H
#define HASH_H

#define TAMANHO_TABELA 10

struct No {
    int valor;
    struct No* proximoNo;
};

extern struct No* tabela[TAMANHO_TABELA];

int hash(int x);
void iniciarTabela();
void adicionar(int valor);
void buscar(int valor);
void imprimirTabela();

#endif
