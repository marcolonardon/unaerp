/*Algoritmo para receber a quantidade de alunos de uma turma e mostrar a média da idade dos alunos*/

#include <stdlib.h>
#include <stdio.h>

float media(int qtdalunos){
	int idade, soma=0;
	
	for(int i=0; i<qtdalunos; i++){
		do{
			printf("Informe a idade do aluno %i: ", i+1);
			scanf("%i", &idade);
			system("cls");
		}while(idade <= 0);
		
		soma += idade;
	}
	
	return soma/float(qtdalunos);
}

int num_alunos(){
	int qtdalunos;
	printf("Insira a quantidade de alunos: ");
	scanf("%i", &qtdalunos);
	
	return qtdalunos;
}

void menu(){
	printf("A media de idades e = %.2f\n\n", media(num_alunos()));
	system("pause");
}

main(){
	menu();
}
