/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "inverter.h"

int main() {
    char str[100];

    printf("Digite uma string: ");
    scanf("%s", str);

    inverterString(str, 0, strlen(str) - 1);

    printf("String invertida: %s\n", str);

    return 0;
}
