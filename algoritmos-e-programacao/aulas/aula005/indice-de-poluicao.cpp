/*A Secretaria do Meio Ambiente mant�m tr�s listas de ind�strias conhecidas por serem altamente poluentes da atmosfera.
Os resultados de v�rias medidas s�o combinados para formar o que � chamado de ��ndice de polui��o�. Isto � controlado regularmente.
Normalmente os valores caem entre .05 e .25 (Bom). 

Se o valor atingir .30 (Ruim), as ind�strias da lista A ser�o chamadas a suspender as opera��es at� que os valores retornem ao intervalo normal.
Se o �ndice atingir .40 (P�ssimo), as ind�strias da lista B ser�o notificadas tamb�m.
Se o �ndice exceder .50 (Cr�tico), ind�strias de todas as tr�s listas ser�o avisadas para suspenderem as atividades.

Preparar um algoritmo para ler o �ndice de polui��o e indicar as nota��es apropriadas.
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
