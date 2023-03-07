/* Determinar o tipo de triângulo com base no comprimento dos dados.
	Ler os três lados do triângulo (L1, L2 e L3 diferentes), e determinar qual é o maior.
	Sendo A o lado maior (hipotenusa):
	Se A >= B + C      =>	nenhum triângulo é formado
	Se A2 = B2 + C2    =>	triângulo retângulo
	Se A2 > B2 + C2	   => 	triângulo obtusângulo
	Se A2 < B2 + C2    => 	triângulo acutângulo   */
	
# include <stdlib.h>
# include <stdio.h>
# include <conio.h>

float l1, l2, l3, a, b, c, aa, bc, bc2 ;
char fim ;

main()
{
	// ler os três lados do triângulo
	printf("Forneca o lado 1: ");
	scanf("%f", &l1);
	printf("Forneca o lado 2: ");
	scanf("%f", &l2);
	printf("Forneca o lado 3: ");
	scanf("%f", &l3);
	
	// determinar qual é o lado maior	
	if( l1 > l2 && l1 > l3)
	{
		a = l1;
		b = l2;
		c = l3;
	}
	if(l2 > l1 && l2 > l3)
	{
		a = l2;
		b = l1;
		c = l3;
	}
	if (l3 > l1 && l3 > l2)
	{
		a = l3;
		b = l1;
		c = l2;
	}
	
	// determinar a soma dos quadrados b2 + c2
	 aa = a*a ;
	bc = b+c ;
	bc2 = b*b + c*c;
	
	// determinar e imprimir o tipo de triângulo
	if (a >= bc)
		printf("\nNenhum triângulo é formado");
	if (aa == bc2)
		printf("\nTriangulo Retangulo");
	if (aa > bc2)
		printf("\nTriangulo Obtusangulo");
	if (aa < bc2)
		printf("\nTriangulo Acutangulo");
		
	fim = getche();
	
}
	
	
