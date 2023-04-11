//calcular a soma dos 100 primeiros termos ==== 1/i  (+- alternados, iniciando com 1 - 1/2 + 1/4)
#include <stdlib.h>
#include <stdio.h>

float soma=1.0;
int denominador=0, mult=1;
main(){
	for(int i=2; i<=100; i++){
		denominador += 2;
		mult *= -1;
		soma += 1.0/denominador * mult;//poderia ser *pow(-1,i-1)
	}
	
	printf("A soma e: %.4f\n\n", soma);
	
	system("pause");
}