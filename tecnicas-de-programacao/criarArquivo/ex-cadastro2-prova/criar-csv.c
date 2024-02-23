/*Marco Antônio Lonardon Júnior - 839462*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 30
#define MAX_EMAIL 25

struct dados_alunos {
/*RA, etapa em que se encontra, ano de inicio, valor da mensalidade, bolsa se houver e e-mails de contato.*/

	int codigo;
	int etapa;
	int ano_inicio;
	float valor_mensalidade;
	float valor_bolsa;
    char email[MAX_EMAIL];
};
struct dados_alunos novoAluno;

void cadastrar_aluno(struct dados_alunos alunos[], int *total_alunos);
void exibir_alunos(struct dados_alunos alunos[], int total_alunos);
void salvarEmArquivo(struct dados_alunos aluno);
float calcular_media(float parcial, float exame);



void cadastrar_aluno(struct dados_alunos alunos[], int *total_alunos) {
    if(*total_alunos >= MAX_ALUNOS){
        printf("Numero maximo de alunos atingido.\n");
        return;
    }

    
    /*codigo, etapa , ano_inicio, valor_mensalidade, valor_bolsa, e-mail*/
    printf("Codigo: ");
    scanf("%i", &novoAluno.codigo);
    
    printf("Etapa: ");
    scanf("%i", &novoAluno.etapa);
    
    printf("Ano de inicio: ");
    scanf("%i", &novoAluno.ano_inicio);
    
    printf("Valor da mensalidade: ");
    scanf("%f", &novoAluno.valor_mensalidade);
    
    printf("Valor da bolsa (se nao houver, insira o valor 0): ");
    scanf("%f", &novoAluno.valor_bolsa);
    
    printf("E-Mail: ");
    scanf("%s", novoAluno.email);



    for (int i = 0; i < *total_alunos; i++) {
        if (novoAluno.codigo == alunos[i].codigo) {
            printf("Aluno ja cadastrado.\n");
            return;
        }
    }

    alunos[*total_alunos] = novoAluno;
    (*total_alunos)++;

    //salvarEmArquivo(novoAluno);
}

void exibir_alunos(struct dados_alunos alunos[], int total_alunos){
/*codigo, etapa , ano_inicio, valor_mensalidade, valor_bolsa, e-mail*/
	printf("CODIGO\tETAPA\tANO\tMENSALIDADE\tBOLSA\tEMAIL\t\n\n");

    for(int i = 0; i < total_alunos; i++){
        printf("%i\t%i\t%i\t%.2f\t\t%.2f\t%s\t\n", alunos[i].codigo,alunos[i].etapa, alunos[i].ano_inicio,
               alunos[i].valor_mensalidade, alunos[i].valor_bolsa, alunos[i].email);
    }
}

void salvarEmArquivo(struct dados_alunos aluno) {
	char nome_arquivo[25];
	printf("\nInforme o nome do arquivo: ");
	scanf("%s", &nome_arquivo);
	
	strcat(nome_arquivo, ".csv");
	
    FILE *arquivo;

    arquivo = fopen(nome_arquivo, "w");

    if(arquivo == NULL){
        printf("Erro!!!\n");
        return;
    }
	
    fprintf(arquivo, "%i;%i;%i;%.2f;%.2f;%s;\n", aluno.codigo, aluno.etapa,
	aluno.ano_inicio, aluno.valor_mensalidade, aluno.valor_bolsa, aluno.email);

    fclose(arquivo);
}

void menu(){
	int op;
    struct dados_alunos alunos[MAX_ALUNOS];
    int total_alunos = 0;

    do{
        printf("\n1 - cadastrar novo;\n2 - listar cadastro;\n3 - gerar csv;\n4 - sair;\n ");
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
            	salvarEmArquivo(novoAluno);
                printf("Arquivo gerado.\n");
                break;
            case 4:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("opcao invalida.\n");
                break;
        }
    }while (op != 4);

}

main() {
    menu();
}
