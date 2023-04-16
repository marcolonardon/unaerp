/*ex 10(b)

 Preparar um algoritmo para calcular o número de pontos como coordenadas de valor inteiro contidas na elipse: 
(1) Os pontos no interior da curva acima são considerados dentro da elipse. 
(2) Os valores das coordenadas estão limitados pelos eixos maior e menor da elipse 
(isto é, - 4 ≤ x ≤ 4  e  - 5 ≤ y ≤ 5)

valores menores que 1 estão dentro da elipse
(x*x/16)+(y*y/25) = 1
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x, y, interno=0;
float f;
main(){
	for(x=-4; x<=4; x++){
		for(y=-5; y<=5; y++){
			f = pow(x,2)/16+pow(y,2)/25;
			if(f<1)
				interno++;
			
			printf("%2.i    %2.i    %2.1f\n",x, y, f);
		}
		
	}
	
	printf("Pontos internos: %i\n\n", interno);
	system ("pause");
	
}