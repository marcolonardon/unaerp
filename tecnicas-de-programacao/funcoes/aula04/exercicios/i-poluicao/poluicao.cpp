/*i) Escreva um procedimento que leia o índice de poluição e indique providências apropriadas.
Índice de poluição i < 0.30 Boa: Nenhuma providência
Índice de poluição 0.30 ≤ i < 0.40 Ruim: Suspender empresas da lista A
Índice de poluição 0.40 ≤ i ≤ 0.50 Péssima: Suspender empresas da lista A e B
Índice de poluição 0.50 < I Crítica: Suspender todas as empresas*/

#include <stdio.h>
#include <stdlib.h>

void poluicao(float x){
	if(x > 0.50){
		printf("\n\nCritica: Suspender todas as empresas.\n\n");
	}else if(x >= 0.40){
		printf("\n\nPessima: Suspender empresas da lista A e B \n\n");
	}else if(x >= 0.30){
		printf("\n\nRuim: Suspender empresas da lista A \n\n");
	}else{
		printf("\n\nBoa: Nenhuma providencia \n\n");
	}
}

int main(){
	poluicao(0.5);
}