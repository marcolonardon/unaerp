/*1) crie um procedimento que receba dois inteiros positivos (deve ser checado) por valor e
devolva no terceiro parâmetro por referência a potência entre os dois parâmetros anteriores. Não usar pow.
*/
#include <stdio.h>

void proc(int base, int expo, int *resultado){
    int res = 1;

    if (base < 0 || expo < 0) {
        printf("Os números devem ser positivos.\n");
        *resultado = -1; 
        return;
    }

    for (int i = 0; i < expo; i++){
        res *= base;
    }

    *resultado = res;
}

void menu(){
    int a = 2, b = 2, pot=0;
    proc(a,b,&pot);
    
    if(pot != 0){
        printf("a^b = %i\n\n", pot);
    }
    
}

int main(){
    menu();
    return 0;
}
