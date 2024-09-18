#include "inverter.h"

void inverterString(char* str, int inicio, int fim) {
    if (inicio >= fim) {
        return; 
    }
    
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    
    inverterString(str, inicio + 1, fim - 1);
}
