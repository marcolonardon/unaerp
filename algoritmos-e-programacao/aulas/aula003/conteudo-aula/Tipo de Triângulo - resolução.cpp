/* Determinar o tipo de tri�ngulo com base no comprimento dos dados.
	Ler os tr�s lados do tri�ngulo (L1, L2 e L3 diferentes), e determinar qual � o maior.
	Sendo A o lado maior (hipotenusa):
	Se A >= B + C      =>	nenhum tri�ngulo � formado
	Se A2 = B2 + C2    =>	tri�ngulo ret�ngulo
	Se A2 > B2 + C2	   => 	tri�ngulo obtus�ngulo
	Se A2 < B2 + C2    => 	tri�ngulo acut�ngulo   */
	
# include <stdlib.h>
# include <stdio.h>
# include <conio.h>

float l1, l2, l3, a, b, c, aa, bc, bc2 ;
char fim ;

main()
{
	// ler os tr�s lados do tri�ngulo
	printf("Forneca o lado 1: ");
	scanf("%f", &l1);
	printf("Forneca o lado 2: ");
	scanf("%f", &l2);
	printf("Forneca o lado 3: ");
	scanf("%f", &l3);
	
	// determinar qual � o lado maior	
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
	
	// determinar e imprimir o tipo de tri�ngulo
	if (a >= bc)
		printf("\nNenhum tri�ngulo � formado");
	if (aa == bc2)
		printf("\nTriangulo Retangulo");
	if (aa > bc2)
		printf("\nTriangulo Obtusangulo");
	if (aa < bc2)
		printf("\nTriangulo Acutangulo");
		
	fim = getche();
	
}
	
	
