/*A Secretaria do Meio Ambiente mantém três listas de indústrias conhecidas por serem altamente poluentes da atmosfera.
Os resultados de várias medidas são combinados para formar o que é chamado de “índice de poluição”. Isto é controlado regularmente.
Normalmente os valores caem entre .05 e .25 (Bom). 

Se o valor atingir .30 (Ruim), as indústrias da lista A serão chamadas a suspender as operações até que os valores retornem ao intervalo normal.
Se o índice atingir .40 (Péssimo), as indústrias da lista B serão notificadas também.
Se o índice exceder .50 (Crítico), indústrias de todas as três listas serão avisadas para suspenderem as atividades.

Preparar um algoritmo para ler o índice de poluição e indicar as notações apropriadas.
*/
#include <stdio.h>
#include <stdlib.h>

float indice;
main(){
	printf("Insira o indice de poluicao: ");
	scanf("%f", &indice);
	
	if(indice > 0.50){
		printf("\nNotificar suspensao de atividades das listas A, B e C.\n\n");		
	}else if(indice >= 0.40){
		printf("\nNotificar suspensao de atividades das listas A e B.\n\n");
	}else if(indice >= 0.30){
		printf("\nNotificar suspensao de atividades da lista A.\n\n");
	}else
		printf("\nIndice dentro do aceitavel. \n\n");

system("pause");	
}
