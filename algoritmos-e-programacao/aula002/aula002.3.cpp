//C para F
//F = C * 9/5 + 32 

#include <stdio.h>
#include <stdlib.h>

float celsius;
main(){
	printf("Isira o valor em celsius: ");
	scanf("%f", &celsius);
	printf("\n%.2f graus celsius sao %.2f Fahrenheit.\n\n", celsius, celsius *(9*1.00/5) + 32);
	
	system("pause");
}
