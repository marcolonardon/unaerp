// C�lculo do pre�o de venda do carro

# include <stdlib.h>
# include <stdio.h>

float custo, imposto, lucro, preco ;

main()
{
	// 1. ler o custo do carro
	printf("Informe o preco de custo: ") ;
	scanf("%f", &custo) ;
	
	// 2. calcular o valor do imposto
	imposto = 0.45 * custo ;
	
	// 3. calcular o valor do lucro
	lucro = 0.12 * (custo + imposto) ;
	
	// 4. calcular o pre�o final
	preco = custo + imposto + lucro ;
	
	// 5. imprimir o pre�o final
	printf("Preco final..: R$%10.2f\n", preco) ;
	printf("Imposto......: R$%10.2f\n", imposto) ;
	printf("lucro........: R$%10.2f\n\n", lucro) ;
	
	// 6. terminar
	system("pause") ;	
	
}
