/*Escreva um programa que permita o cadastro de alunos e suas notas.

Os dados cadastrados devem ser salvos em arquivo, portanto, não se perdem quando o programa finaliza.

Segue a estrutura do arquivo:

RA        NOME    PARCIAL     EXAME     MEDIA
123456    Joao    5.0         5.0       5.0

O menu de opções deve conter:
1) Cadastrar novo alunos
2) Exibir alunos cadastrados.
3) Sair*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 30
#define MAX_NOME 100

int flag=1;

struct dados_alunos {
    char nome[MAX_NOME];
    int codigo;
    float nota_parcial;
    float nota_exame;
};

void cadastrar_aluno(struct dados_alunos alunos[], int *total_alunos);
void exibir_alunos(struct dados_alunos alunos[], int total_alunos);
void salvarEmArquivo(struct dados_alunos aluno);
float calcular_media(float parcial, float exame);



void cadastrar_aluno(struct dados_alunos alunos[], int *total_alunos) {
    if(*total_alunos >= MAX_ALUNOS){
        printf("Numero maximo de alunos atingido.\n");
        return;
    }

    struct dados_alunos novoAluno;

    printf("Nome: ");
    scanf("%s", novoAluno.nome);

    printf("Codigo: ");
    scanf("%i", &novoAluno.codigo);

    for (int i = 0; i < *total_alunos; i++) {
        if (novoAluno.codigo == alunos[i].codigo) {
            printf("Aluno ja cadastrado.\n");
            return;
        }
    }

    printf("Parcial: ");
    scanf("%f", &novoAluno.nota_parcial);

    printf("Exame: ");
    scanf("%f", &novoAluno.nota_exame);

    alunos[*total_alunos] = novoAluno;
    (*total_alunos)++;

    salvarEmArquivo(novoAluno);
}

void exibir_alunos(struct dados_alunos alunos[], int total_alunos){
    printf("\nAlunos cadastrados:\n");
    printf("RA\t\tNOME\t\tPARCIAL\t\tEXAME\t\tMEDIA\n");

    for(int i = 0; i < total_alunos; i++){
        float media = calcular_media(alunos[i].nota_parcial, alunos[i].nota_exame);
        printf("%i\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", alunos[i].codigo, alunos[i].nome,
               alunos[i].nota_parcial, alunos[i].nota_exame, media);
    }
}

void salvarEmArquivo(struct dados_alunos aluno) {
    FILE *arquivo;

    arquivo = fopen("cadastro.txt", "a");

    if(arquivo == NULL){
        printf("Erro!!!\n");
        return;
    }
	
	if(flag==1){
		fprintf(arquivo, "CODIGO\tNOME\tPARCIAL\tEXAME\tMEDIA\t\n\n");
		flag++;
	}
	
    fprintf(arquivo, "%i\t%s\t%.2f\t%.2f\t%.2f\t\n", aluno.codigo, aluno.nome,
            aluno.nota_parcial, aluno.nota_exame, calcular_media(aluno.nota_parcial, aluno.nota_exame));

    fclose(arquivo);
}

float calcular_media(float parcial, float exame){
    return (parcial*0.4)+(exame*0.6);
}

void menu(){
	int op;
    struct dados_alunos alunos[MAX_ALUNOS];
    int total_alunos = 0;

    do{
        printf("\n1) Cadastrar novo aluno\n2) Exibir alunos cadastrados\n3) Sair\n");
        printf("\nEscolha a opcao: ");
        scanf("%i", &op);

        switch (op) {
            case 1:
                cadastrar_aluno(alunos, &total_alunos);
                break;
            case 2:
                exibir_alunos(alunos, total_alunos);
                break;
            case 3:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("opcao invalida.\n");
                break;
        }
    }while (op != 3);

}

main() {
    menu();
}