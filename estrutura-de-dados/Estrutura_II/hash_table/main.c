#include <stdio.h>
#include "hash.h"

void menu(){
    int opcao, valor;
    
    do {
        printf("\nMenu de Opcoes:\n");
        printf("1. Adicionar valor\n");
        printf("2. Buscar valor\n");
        printf("3. Imprimir tabela de hash\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor para adicionar: ");
                scanf("%d", &valor);
                adicionar(valor);
                break;
            case 2:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                buscar(valor);
                break;
            case 3:
                printf("\nTabela Hash:\n");
                imprimirTabela();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 4);
}

int main() {
    iniciarTabela();
    menu();
    
    return 0;
}


