/*e) Escreva uma função que receba 4 notas e retorne um valor verdade, de forma que identifique se o aluno
está aprovado ou não. Considere a média de corte 7,0.*/

#include <stdio.h>
#include <stdlib.h>

bool media(float n1, float n2, float n3, float n4){
    float res = (n1 + n2 + n3 + n4) / 4.0;

    printf("\nMedia final: %.2f\n", res);

    if(res >= 7.0){
        return true;
    }else{
        return false;
    }
}

int main(){
    float notas[3];

    for(int i = 0; i < 4; i++){
        printf("\nInsira a nota %i: ", i+1);
        scanf("%f", &notas[i]);
    }

    if(media(notas[0], notas[1], notas[2], notas[3]))
        printf("\nSituacao do aluno: APROVADO\n\n");
    else
        printf("\nSituacao do aluno: REPROVADO\n\n");

}