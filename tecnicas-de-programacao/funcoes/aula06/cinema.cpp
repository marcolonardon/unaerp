/*Seu cliente tem uma sala de cinema  6x10 lugares. Escreva um software para o gerenciametno desses lugares.
Escreva um programa com as seguintes opções:
1) Exibir sala:
2) escolher lugar
3) sair

onde a opção 1 deve mostrar na tela a quantidade de lugares disponíveis e a sala em forma de matriz;
A opção 2 deve exibir a sala, mostrar a poltronas que estão ocupadas com um X, e as disponíveis com um número.
O usuário deve poder escolher uma poltrona que esteja vazia.

3) finaliza*/

#include <stdio.h>
#include <stdlib.h>
#define COLUNA 6
#define LINHA 10

int lugares[COLUNA][LINHA], disp = 0;

void resetar_assentos(){
    int aux = 1;
    for (int i = 0; i < COLUNA; i++){
        for(int j = 0; j < LINHA; j++){
            lugares[i][j] = aux;
            aux++;
        }
    }
}

void assentos_disponiveis(){
    disp = 0;
    for(int i = 0; i < COLUNA; i++){
        for(int j = 0; j < LINHA; j++){
            if(lugares[i][j] > 0){
                printf("%i\t", lugares[i][j]);
                disp++;
            }
            else{
                printf("X\t");
            }
        }
        printf("\n");
    }
}

void escolher_assento(){
    int lugar_escolha;
    assentos_disponiveis();

    if (disp > 0){
        printf("\nEscolha o numero do seu lugar: ");
        scanf("%i", &lugar_escolha);

        if(lugar_escolha >= 1 && lugar_escolha <= COLUNA * LINHA){
            int encontrado = 0;

            for(int i = 0; i < COLUNA; i++){
                for(int j = 0; j < LINHA; j++){
                    if(lugares[i][j] == lugar_escolha){
                        if(lugares[i][j] == 0){
                            printf("\nEsse assento ja esta ocupado.\n\n");
                        }
                        else{
                            lugares[i][j] = 0;
                            printf("\nAssento %i escolhido com sucesso.\n\n", lugar_escolha);
                        }
                        encontrado = 1;
                        break;
                    }
                }
                if (encontrado){
                    break;
                }
            }

            if (!encontrado){
                printf("\nO assento %i nao esta disponivel.\n\n", lugar_escolha);
            }
        }
        else{
            printf("\nNumero de assento invalido.\n\n");
        }
    }
    else{
        printf("\nTodos os lugares foram ocupados\n\n");
    }
}

void casos(int op){
    system("cls");

    switch(op){
    case 1:
        assentos_disponiveis();
        printf("\nLugares disponiveis: %i\n\n", disp);
        break;
    case 2:
        escolher_assento();
        break;
    case 3:
        printf("\n\nFinalizando programa\n\n");
        break;

    default:
        printf("\n\nOpcao invalida\n\n");
        break;
    }
}

void menu(){
    int op;

    resetar_assentos();

    do{
        printf("1) Exibir sala\n2) Escolher Lugar\n3) Sair\nEscolha a opcao: ");
        scanf("%i", &op);

        casos(op);

    }while(op != 3);
}

main(){
    menu();
}