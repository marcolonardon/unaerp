// Desconto na compra de álcool ou gasolina
// alcool - 2,09 com desconto 3% até 20l  e  5% mais de 20l
// gasolina 2,99 com desconto 4% até 20l  e  6% mais de 20l 
// ler o tipo de combustivel e litros e 
// imprimir o valor sem desconto, o desconto 
// e o valor com desconto

#include<stdio.h>
#include<stdlib.h>

char tipo ;
int flag = 1;
float litros, desconto, valorbruto, valordesconto ;

main()
{
	printf("Tipo de combustivel (A: alcool, G: gasolina): ");
	scanf("%c", &tipo);
	printf("Quantidade abastecida (Litros): ");
	scanf("%f", &litros);
	
	if(tipo == 'A' || tipo == 'a')
	{
		valorbruto = 2.09 * litros ;
		if(litros > 20 )
			desconto = valorbruto * 0.05 ;	
		else 
			desconto = valorbruto * 0.03 ;
		
		valordesconto = valorbruto - desconto ;
	}
	else if(tipo == 'G' || tipo == 'g')
	{
		valorbruto = 2.99 * litros ;
		if(litros > 20 )
			desconto = valorbruto * 0.06 ;	
		else 
			desconto = valorbruto * 0.04 ;
		
		valordesconto = valorbruto - desconto ;
	}
	else
		flag = 0 ;
	
	if(flag == 1 )
	{
		printf("\n\nValor sem desconto: R$ %.2f\n", valorbruto);
		printf("Valor com desconto: R$ %.2f\n", valordesconto);
		printf("Valor do desconto: R$ %.2f\n\n", desconto);
	}
	else
		printf("\nVoce nao escolheu nem Alcool nem Gasolina\n\n");
	
	system("pause");	
}





