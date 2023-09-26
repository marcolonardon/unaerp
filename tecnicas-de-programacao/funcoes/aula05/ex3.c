/*3) Escreva um procedimento que encontre todos os números primos no intervalo 1-n.
*/
#include <stdio.h>

int primo(int num){
    if(num < 2){
        return 0;
    }
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

void ep(int n){
    if(n < 2){
        printf("Não existem números primos no intervalo de 1 a %i.\n", n);
        return;
    }
    printf("Números primos no intervalo de 1 a %i:\n", n);
    for(int i = 2; i <= n; i++){
        if(primo(i)) {
            printf("%i ", i);
        }
    }
    printf("\n");
}

void menu(){
    int n;
    
    printf("Digite o valor de n: ");
    scanf("%i", &n);

    ep(n);
}

int main(){
    
    menu();

    return 0;
}
