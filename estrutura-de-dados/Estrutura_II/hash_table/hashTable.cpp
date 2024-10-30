/*
Implemente um programa em C que utilize uma tabela hash para armazenar números inteiros. A estrutura da tabela hash deve ser um 
array de 10 posições, em que a função hash será definida 
como `hash(x) = x % 10`. Para tratar colisões, utilize listas lineares encadeadas (listas ligadas) em cada posição do array.
*/

#include <stdio.h>
#include <stdlib.h>

int vetor[10];
int *ponteiros[10];


struct No{
  int valor;
  Node* proximoNo;
}

int hash(int x){
	return x%10;
}

void adicionarAoVetor(int valor, int posi){
	vetor[posi] = valor;
}

int main(){
	int valor;
	scanf("%i", &valor);
	printf("Valor gerado na func hash = %i", hash(valor));
	return 0;
}