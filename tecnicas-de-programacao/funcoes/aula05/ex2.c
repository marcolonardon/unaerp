/*2) Escreva uma função que receba por valor um inteiro positivo e retorne o fatorial do mesmo.
*/
#include <stdio.h>

int fat(int x){
    int res = x;
    for(int i = 1; i < x; i++){
        res *= i;
    }
    
    return res;
}

void menu(){
    int x = 3;
    printf("%i! = %i\n\n", x, fat(x));
}

int main(){
    menu();
    return 0;
}
