/* Area do triangulo: algoritmo para ler a base e a altura de um triangulo e
imprimir a base, altura e area.
verificar se abase e/ou a altura e negativa. Caso afirmativo, impriir mensagem de erro e nao calcular a area.
Caso a base e a altura sejam ambas negativas, imprimir mensagem e nao calcular a area*/

#include <stdlib.h>
#include <stdio.h>

float base, h, area;

main(){
	printf("Insira o valor da base do triangulo: ");
	scanf("%f", &base);
	printf("\nInsira o valor da altura do triangulo: ");
	scanf("%f", &h);
	
	if (base < 0 && h < 0){
		printf("\nERRO! Base e altura negativas.\n\n");
	}else if(base < 0 && h > 0){
		printf("\nERRO! Base negativa.\n\n");
	}else if(base > 0 && h < 0){
		printf("\nAltura negativa, nao e possivel calcular a area.\n\n");
	}else{
		area = (base*h)/2;
		printf("\nA area de um triangulo de base: %.2f e altura: %.2f eh %.2f\n\n", base, h, area);
	}
	
	system("pause");
}
