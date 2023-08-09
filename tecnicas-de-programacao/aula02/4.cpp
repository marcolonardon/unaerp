/*Função que verifica se um número é par.*/
#include <stdio.h>
#include <stdlib.h>

 bool par(int valor){
    if(valor%2 == 0){
    	return true;
    }else{
    	return false;
    }
}

int main(){
    int valor;
    printf("\nInsara um valor para verificar se e impar ou par: ");
    scanf("%i", &valor);

	printf("%i %s",valor, par(valor) ? "e par":"e impar");
}