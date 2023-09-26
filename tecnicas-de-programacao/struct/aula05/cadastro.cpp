/*Crie um programa modularizado que cadastre até 30 alunos de uma sala.
O dados são ra, parcial e exame.

A função main deve ter apenas o seguinte conteúdo:

int main (){
 declaração dos dados que achar pertinentes;
 menu(parâmetros pertinentes);
}

O menu deve colocar na tela as seguintes opções:
TOTAL DE ALUNOS = XX
 1- Cadastrar
 2- Listar
 3- Pesquisar
 4- Sair

Funcionamento de cada opção:
* cadastrar - Deve pedir os dados ao usuário. Alunos já cadastrados devem ser impedidos com mensagem adequada.
* listar - exibir todos os dados dos alunos cadastrados em forma de tabela, incluindo a média ponderada (segundo unaerp) e status (APR/REP)
* Pesquisar - caso não encontre, mostrar mensagem adequada. Caso encontre,
exibir as mesmas informações do item anterior, porém apenas do aluno
em específico.
* Sair - Finalizar o programa quando o usuário quiser.*/

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
int total_alunos=0, opcao=0, code;
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
	int flag = 1;
    if(total_alunos >= MAX_ALUNOS){
        printf("Numero maximo de alunos atingido.\n\n");
        return;
    }

    dados_alunos novo_aluno;

    printf("Nome: ");
    scanf("%s", &novo_aluno.nome);

    printf("Codigo: ");
    scanf("%i", &novo_aluno.codigo);	
	for(int i = 0; i < MAX_ALUNOS; i++){
		if(novo_aluno.codigo == alunos[i].codigo){
			flag=0;
			printf("\nAluno ja cadastrado.\n");
			break;
		}
	}
    
    if(flag){
    	    printf("Parcial: ");
    scanf("%f", &novo_aluno.nota_parcial);

    printf("Exame: ");
    scanf("%f", &novo_aluno.nota_exame);

    printf("Faltas: ");
    scanf("%i", &novo_aluno.faltas);

    alunos[total_alunos++] = novo_aluno;
    	
	}
	flag = 1;



}

void listar_alunos(){
    printf("\nCODIGO\tNOME\tPARCIAL\tEXAME\tMEDIA\tFALTAS\tSTATUS\n");
    printf("-------------------------------------------------------\n");

    for(int i = 0; i < total_alunos; i++){
        float media = calcular_media(alunos[i].nota_parcial, alunos[i].nota_exame);
        const char* situacao = condicao_final(media, alunos[i].faltas);

        printf("%i\t%s\t%.1f\t%.1f\t%.1f\t%i\t%s\t\n", alunos[i].codigo, alunos[i].nome, alunos[i].nota_parcial, alunos[i].nota_exame, media, alunos[i].faltas, situacao);

    }
    
}

void listar_um_aluno(int i){
    printf("\nCODIGO\tNOME\tPARCIAL\tEXAME\tMEDIA\tFALTAS\tSTATUS\n");
    printf("-------------------------------------------------------\n");

    float media = calcular_media(alunos[i].nota_parcial, alunos[i].nota_exame);
    const char* situacao = condicao_final(media, alunos[i].faltas);

    printf("%i\t%s\t%.1f\t%.1f\t%.1f\t%i\t%s\t\n", alunos[i].codigo, alunos[i].nome, alunos[i].nota_parcial, alunos[i].nota_exame, media, alunos[i].faltas, situacao);

}
void pesquisar (int code){
	for(int i = 0; i < MAX_ALUNOS; i++){	
		if(alunos[i].codigo == code){
			listar_um_aluno(i);
			break;	
		}
		if(i == code+1)
			printf("\nAluno nao encontrado.\n\n");
	}

}

void menu(){
	    typedef dados_alunos dados;

    do  {
        printf("\nTOTAL DE ALUNOS = %i\n", total_alunos);
        printf("1) Cadastrar\n2) Listar\n3) Pesquisar \n4) Sair\nEscolha uma opcao: ");
        scanf("%i", &opcao);

        switch (opcao){
        case 1:
            system("cls");
            adicionar_alunos();
            break;

        case 2:
            system("cls");
            listar_alunos();
            break;

        case 3:
            system("cls");
            printf("\nInsira o codigo do aluno pesquisado: ");
            scanf("%i", &code);
            pesquisar(code);
            break;
        
        case 4:
            system("cls");
            printf("Finalizando programa.\n\n");
            break;
        
        default:
            printf("Opcao invalida.\n\n");
            break;
        }

    } while (opcao!=4);

}

int main(){
	menu();
}