//elaborar algoritmo para ler o tempo que um nadador percorre 100m e calcular o tempo para percorrer 100 jardas
//1 jarda = 0.9144m


#include <stdio.h>
#include <stdlib.h>

float seg;
main(){
	printf("Segundos para nadar 100m: ");
	scanf("%f", &seg);
	printf("\n100m em %.2fs representam 100j em %.2fs\n\n", seg, seg*0.9144 );
	
	system("pause");
}
