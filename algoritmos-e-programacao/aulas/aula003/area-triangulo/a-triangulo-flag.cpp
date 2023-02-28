/* Area do triangulo: algoritmo para ler a base e a altura de um triangulo e
imprimir a base, altura e area.
verificar se abase e/ou a altura e negativa. Caso afirmativo, impriir mensagem de erro e nao calcular a area.
Caso a base e a altura sejam ambas negativas, imprimir mensagem e nao calcular a area*/

#include <stdlib.h>
#include <stdio.h>

float base, h, area;
int flag=0;

main(){
	printf("Insira o valor da base do triangulo: ");
	scanf("%f", &base);
	printf("\nInsira o valor da altura do triangulo: ");
	scanf("%f", &h);
	
	if (base < 0){
		flag ++;	
	}
	if (h < 0){
		flag ++;
	}
	if (flag > 0){
		if (flag == 2){
			printf("\nERRO! Base e altura negativas.\n\n");
		}else{
			printf("\nERRO! Base negativa.\n\n");
		}
	}else{
		area = (base*h)/2;
		printf("\nBase   = %.2f\nAltura = %.2f\nArea   = %.2f\n\n", base, h, area);
	}
	
	system("pause");
}
