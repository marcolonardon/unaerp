//ex 10(a)
//Preparar um algoritmo para calcular e tabular os valores da função:
//para	x = 2, 4, 6, 8
//   	y = 6, 9, 12, 15, 18, 21
//f(f,x)= (x^2-y^2)/(x^2+y^2)
#include <stdio.h>
#include <stdlib.h>

int x, y;
float f;
main(){
	printf(" x    y    f(x,y)\n");
	printf("-----------------\n");
	for(x=2; x<=8; x+=2){
		for(y=6; y<=21; y+=3){
			f=1.0*(x*x-y*y)/(x*x+y*y);
			printf(" %i    %2.i    %5.2f\n", x, y, f);
		}	
	}
	printf("-----------------\n");
	system("pause");
	
}