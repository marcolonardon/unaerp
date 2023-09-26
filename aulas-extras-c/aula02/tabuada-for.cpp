/*Usa-se o for quando sabe-se com anteced�ncia quantas vezes ocorrer� uma repeti��o
sintaxe:
	for(inicializar a vari�vel de controle do loop; condi��o de parada; incremento/decremento da vari�vel de controle)


Criar calculadora de tabuada
*/

#include <stdio.h>
#include <stdlib.h>

void tabuada(int x){
	for(int i=0; i < 11; i++){
		printf("%i x %i = %i\t\n", x, i, x*i);
	}
}

void opcao(int& op){
		do{
			printf("\n1 - Fazer outra tabuada\n2 - Sair\nEscolha uma opcao: ");
			scanf("%i", &op);
			system("cls");
				
		}while(op!=1 && op!=2);
	
}

void menu(){
	int x, op=1;
	do{
		printf("Insira o valor da tabuada que deseja: ");
		scanf("%i", &x);
		system("cls");
		
		tabuada(x);
		
		opcao(op);

			
	}while(op == 1);

	printf("\n\nFinalizando programa...\n\n");
}

main(){
	menu();
}
