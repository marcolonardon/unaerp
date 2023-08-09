#include <stdio.h>
#include <string.h>
#define MAX 30
typedef struct
{
    int codigo;
    float notas[2];
    int faltas;
    char nome[30];
} Aluno;

Aluno alunos[MAX];
int nalunos = -1;

int main()
{
    int op;
    do
    {
        printf("\nTotal alunos: %d\n\n1) Adicionar\n2) Listar\n3) Sair\nOpcao....: ", nalunos + 1);
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            if (nalunos == (MAX - 1))
                printf("\nTurma Lotada\n");
            else
            {
                nalunos++;
                printf("Digite o RA, nome, Parcial, Exame e faltas:\n->  ");
                scanf("%d", &alunos[nalunos].codigo);
                scanf("%s", &alunos[nalunos].nome);
                fflush(stdin);
                scanf("%f%f%d", &alunos[nalunos].notas[0], &alunos[nalunos].notas[1],
                      &alunos[nalunos].faltas);
            }
            break;
        case 2:
            printf("\nCODIGO\tNome\t\tPARCIAL\tEXAME\tMEDIA\tFaltas\tStatus");
            if (nalunos == -1)
                printf("\nLista vazia");
            else
                for (int i = 0; i <= nalunos; i++)
                    printf("\n%d\t%s\t\t%.1f\t%.1f\t%.1f\t%d\t%s", alunos[i].codigo,
                           alunos[i].nome, alunos[i].notas[0], alunos[i].notas[1],
                           alunos[i].notas[0] * .4 + alunos[i].notas[1] * .6,
                           alunos[i].faltas,
                           (alunos[i].notas[0] * .4 + alunos[i].notas[1] * .6) >= 5.0 ? "APR" : "REP");
            break;
        case 3:
            break;
        default:
            printf("\nEscolha entre 1, 2 e 3: ");
            break;
        }
        if (op == 3)
            break;
    } while (1);
}