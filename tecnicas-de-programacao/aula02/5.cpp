/*Procedimento que adiciona um valor a cada elemento de um array e outro para imprimir o array.*/

#include <stdio.h>
#include <stdlib.h>

const int MAX = 30;
int i = 0;

char array[MAX];
void adicionar(){
	int op, valor;
//	system("cls");
	printf("1) Adicionar\n2) Remover\nSelecione uma opcao: ");
	scanf("%i", &op);
	switch (op){
		case 1: 
			printf("\nQual valor deseja adicinar? ");
			scanf("%i", &valor);
			array[i] = valor;
			i++;
			break;
		case 2: 
			for(int i2=0; i2 <= i; i2++){
				printf("%i ", array[i2]);
			}
			
			break;
		defaut:
			break;
		
	}
}
void imprimir (){
	
}

int main(){
	
	
	do{
		imprimir();
	}while(1);
	
}