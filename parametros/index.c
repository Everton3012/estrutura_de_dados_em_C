#include <stdio.h>
#include <stdlib.h>

void dobrar(int x)
{
    x = x * 2;
    printf("Dentro da função: %d\n", x);
}

int main()
{
    system("chcp 65001 > nul");

    int numero = 5;
    dobrar(numero);
    printf("Fora da função: %d\n", numero);
    return 0;
}