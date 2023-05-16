// calcular o valor de p(x) = a0x^4 + a1x^3 + a2x^2 + a3x^1 + a4

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int i, n=5;
float x, px=0.0, a[5];


main(){
	for(i=0; i<n;i++){
		printf("Informe o valor dar posicao %i: ", i+1);
		scanf("%f", &a[i]);
	}
	
	printf("\nInforme o valor de x: ");
	scanf("%f", &x);
	
	for(i=0; i<n; i++){
		px += a[i]*pow(x, n-(i+1));
	}
	
	printf("O valor de p(x) para x=%.2f e %.2f\n\n", x, px);
	system("pause");
}