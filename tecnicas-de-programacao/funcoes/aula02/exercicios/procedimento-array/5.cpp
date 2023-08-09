/*Procedimento que adiciona um valor a cada elemento de um array e outro para imprimir o array.*/

#include <stdio.h>
#include <stdlib.h>

const int MAX = 3;
int i = -1, op;

int array[MAX];

void imprimir(){
	system("cls");
	if (i == -1){
		printf("\nNenhum valor foi adicionado.\n");
	}
	else{
		printf("Sequencia: ");
		for (int i2 = 0; i2 <= i; i2++){
			printf("%i ", array[i2]);
		}
	}
}

void adicionar(){
	int valor;
	printf("\nValores adicionados: %i de %i\n\n1) Adicionar\n2) Listar\n3) Sair\nSelecione uma opcao: ", i + 1, MAX);
	scanf("%i", &op);
	switch (op){
	case 1:
		if(i+1 == MAX){
			system("cls");
			printf("\nLimite de valores atingido.");
		}else{
			i++;
			printf("\nValor a ser adicionado: ");
			scanf("%i", &valor);
			array[i] = valor;
		}
		
		break;
	case 2:
		imprimir();
		break;
	case 3:
		break;
	defaut:
		printf("\nSelecione um valor valido\n");
		break;
	}
}

int main(){
	do{
		adicionar();

		if (op == 3){
			break;
		}

	} while (true);
}