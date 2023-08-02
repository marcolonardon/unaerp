/*Escreva um programa que cadastre até 30 alunos.
Para cada aluno registre RA, Nome, Parcial, Exame e faltas.
O programa deve ter um menu com as opções:
Total de Alunos: ??
1) Adicionar
2) Listar
3) Sair

Onde, 
* ?? é o número de alunos cadastrados;
*Quando selecionada a opção listar, os seguintes dados devem ser exibidos em forma de tabela
CODIGO  NOME  PARCIAL  EXAME  MEDIA FALTAS  STATUS
* A exibição das notas e médias devem ser feitas com 1 casa decimal
* O Status deve exibir APR ou REP de acordo com a regra da instituição, assim como a MÉDIA.*/


#include <stdio.h>
#include <stdlib.h>

struct dados_alunos{
    char nome[100];
    int codigo;
    int faltas;
    float nota_parcial;
    float nota_exame;
};

const int MAX_ALUNOS = 30;
int total_alunos=0, opcao=0;
dados_alunos alunos[MAX_ALUNOS];

float calcular_media(float parcial, float exame){
    return (parcial*0.4)+(exame*0.6);   
}

const char* condicao_final(float media, int faltas){
    if(media > 6 && faltas < 10){
        return "APR";
    }else{
        return "REP";
    }
}

void adicionar_alunos(){
    if(total_alunos >= MAX_ALUNOS){
        printf("Numero maximo de alunos atingido.\n\n");
        return;
    }

    dados_alunos novo_aluno;

    printf("Nome: ");
    scanf("%s", &novo_aluno.nome);

    printf("Codigo: ");
    scanf("%i", &novo_aluno.codigo);

    printf("Parcial: ");
    scanf("%f", &novo_aluno.nota_parcial);

    printf("Exame: ");
    scanf("%f", &novo_aluno.nota_exame);

    printf("Faltas: ");
    scanf("%i", &novo_aluno.faltas);

    alunos[total_alunos++] = novo_aluno;

}

void listar_alunos(){
    printf("\nCODIGO\tNOME\tPARCIAL\tEXAME\tMEDIA\tFALTAS\tSTATUS\n");
    printf("-------------------------------------------------------\n");

    for(int i = 0; i < total_alunos; i++){
        float media = calcular_media(alunos[i].nota_parcial, alunos[i].nota_exame);
        const char* situacao = condicao_final(media, alunos[i].faltas);

        printf("%i\t%s\t%.2f\t%.2f\t%.2f\t%i\t%s\t\n", alunos[i].codigo, alunos[i].nome, alunos[i].nota_parcial, alunos[i].nota_exame, media, alunos[i].faltas, situacao);

    }
    
}

int main(){
    typedef dados_alunos dados;

    do  {
        printf("\nTotal de Alunos: %i\n", total_alunos);
        printf("1) Adicionar\n2) Listar\n3) Sair\nEscolha uma opcao: ");
        scanf("%i", &opcao);

        switch (opcao){
        case 1:
            adicionar_alunos();
            break;

        case 2:
            listar_alunos();
            break;

        case 3:
            printf("Finalizando programa.\n\n");
            break;
        
        default:
            printf("Opcao invalida.\n\n");
            break;
        }

    } while (opcao!=3);

    return 0;
}