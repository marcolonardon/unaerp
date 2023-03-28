/*Aquiles e a tartaruga disputam uma corrida. 
Aquiles corre dez vezes mais rápido do que a tartaruga, porém a tartaruga 
tem 100 metros de vantagem. Pode-se argumentar que Aquiles nunca ultrapassará 
a tartaruga, pois, quando ele atingir o ponto onde a tartaruga estava, 
ela já estará um pouco à frente. Projetar um algoritmo para ler a velocidade 
da tartaruga e calcular o tempo no qual Aquiles ultrapassará a tartaruga.
*/

#include <stdio.h>
#include <stdlib.h>

float velocidade, dT=100, dA=0;
int seg=0;
main(){
    printf("Informe a velocidade da tartaruga(m/s): ");
    scanf("%f", &velocidade);

    do{
        seg++;
        dT += 1;
        dA += 10*velocidade;

    }while(dT > dA);

    printf("A tartaruga sera ultrapassada no segundo %d\n\n", seg);

    system("pause");
}