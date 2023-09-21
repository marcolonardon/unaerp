/*Estrutura condicional
- if
- switch


if(condição1){
	//instruções
}else if(condição2){
	//instruções
}else{
	//instruções
}

switch(variavel){
	case 1: //instrução
	break; //se não colocar o break, vai passar pelo case
	
	case 2: //instrução
	break; //se não colocar o break, vai passar pelo case
	
	default: //instrução - quando não entra em nenhum case

}*/


/*Elaborar um algoritmo para ler o salário e mostrar o valor de IR a ser pago

De	        Até	        Alíquota	Parcela a deduzir
0,00    	2.112,00	0,00%	    0,00
2.112,01	2.826,65	7,50%	    158,40
2.826,66	3.751,06	15,00%   	370,40
3.751,07	4.664,68	22,50%  	651,73
acima de    4.664,69	27,50%  	884,96


*/
#include <stdio.h>
#include <stdlib.h>

float calculo(float salario, float& imposto){
	
	if(salario >= 4664.69){
		imposto = salario*0.275 - 884.96;
		salario -= imposto;
	}else if(salario >= 3751.07){
		imposto = salario*0.225 - 651.73;
		salario -= imposto;
	}else if(salario >= 2826.66){
		imposto = salario*0.15 - 370.40;
		salario -= imposto;
	}else if(salario >= 2112.01){
		imposto = salario*0.075 - 158.40;
		salario -= imposto;
	}else{
		imposto = 0;
	}
	
	return salario;
}

void menu(){
	float salario, imposto=0;
	printf("Insira seu salario: ");
	scanf("%f", &salario);
	
	printf("\nSalario inicial: R$%.2f\nSalario apos o calculo do I.R.: R$%.2f\n", salario, calculo(salario, imposto));
	printf("Total a ser pago: R$%.2f\n\n", imposto);
	
	system("pause");
}

main(){
	menu();
}
