/*Algoritmo paara ler a nota parcial e mostrar a nota final m�nima que dever conseguirda para aprova��o, considerando que prova*/

#include <stdlib.h>
#include <stdio.h>

float calculo(float x){
	float necessario = (5 - x * 0.4) / 0.6;
	
	return necessario;
}

void menu(){
	float parcial;
	printf("Insira a nota parcial: ");
	scanf("%f", &parcial);
	system("cls");
	printf("\nNota necessaria para aprovacao: %.2f\n\n", calculo(parcial) );
	system("pause");
}

main(){
	menu();
}
