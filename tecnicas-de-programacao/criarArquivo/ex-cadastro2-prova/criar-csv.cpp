/*ATIVIDADE: Escreva um software que leia para um vetor de struct
em memória o RA, etapa em que se encontra, ano de inicio, valor
da mensalidade, bolsa se houver e e-mails de contato. 




O programa deve conter no menu: 1 – cadastrar novo; 
								2- listar cadastro ; 
								3 - gerar csv; 
								4 – sair; 
								
onde, o item 1 preenche o vetor um estudante
por vez; 
o item 2 exibe o vetor em forma tabelada;
 o tem 3 pede o
nome do arquivo e salva o conteúdo do vetor em um arquivo .csv,
com campos separados por “;” 
e finalmente o item 4 encerra o programa.


* Corpo da função principal deve ser:
int main (){ menu(parâmetros); } onde antes da chamada de
menu é permitida a declaração da dados e estruturas de dados
necessárias. (qualquer outra modificação,
* Bibliotecas autorizadas: stdio.h e stdlib.h (adição de
outras modifica o escopo)

COMO ENTREGAR:

* Nome e RA do estudante deve constar no início do arquivo-fonte
principal (que contém a função main)em forma de comentário.
(redução de 10% da nota)
* Entregar exclusivamente pelo classroom, os arquivos originais.
Links não serão aceitos.
* Não compactar. (redução de 1/3 da nota).*/

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#define MAX_ALUNOS 30
#define MAX_EMAIL 25

int flag=1;

struct dados_alunos {
/*RA, etapa em que se encontra, ano de inicio, valor da mensalidade, bolsa se houver e e-mails de contato.*/

	int codigo;
	int etapa;
	int ano_inicio;
	int valor_mensalidade;
	int valor_bolsa;
    char email[MAX_EMAIL];
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
    
    /*codigo, etapa , ano_inicio, valor_mensalidade, valor_bolsa, e-mail*/
    printf("Codigo: ");
    scanf("%i", &novoAluno.codigo);
    
    printf("Etapa: ");
    scanf("%i", &novoAluno.etapa);
    
    printf("Ano de inicio: ");
    scanf("%i", &novoAluno.ano_inicio);
    
    printf("Valor da mensalidade: ");
    scanf("%i", &novoAluno.valor_mensalidade);
    
    printf("Valor da bolsa (se nao houver, insira o valor 0): ");
    scanf("%i", &novoAluno.valor_bolsa);
    
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

    salvarEmArquivo(novoAluno);
}

void exibir_alunos(struct dados_alunos alunos[], int total_alunos){
    printf("\nAlunos cadastrados:\n");
/*codigo, etapa , ano_inicio, valor_mensalidade, valor_bolsa, e-mail*/
	printf("CODIGO\tETAPA\tANO\tMENSALIDADE\tBOLSA\tEMAIL\t\n\n");

    for(int i = 0; i < total_alunos; i++){
        printf("%i\t%i\t%i\t%.2f\t%.2f\t%s\t\n", alunos[i].codigo,alunos[i].etapa, alunos[i].ano_inicio,
               alunos[i].valor_mensalidade, alunos[i].valor_bolsa, alunos[i].email);
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
		 /*codigo, etapa , ano_inicio, valor_mensalidade, valor_bolsa, e-mail*/
		fprintf(arquivo, "CODIGO\tETAPA\tANO\tMENSALIDADE\tBOLSA\tEMAIL\t\n\n");
		flag++;
	}
	
    fprintf(arquivo, "%i\t%i\t%i\t%.2f\t%.2f\t%s\t\n", aluno.codigo, aluno.etapa,
	aluno.ano_inicio, aluno.valor_mensalidade, aluno.valor_bolsa, aluno.email);

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
