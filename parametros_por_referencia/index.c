#include <stdio.h>
#include <stdlib.h>

void dobrar(int *x)
{
    *x = (*x) * 2;
}

int main()
{
    system("chcp 65001 > nul");

    int numero = 5;
    printf("Número antes de dobrar: %d\n", numero);
    dobrar(&numero);
    printf("Número dobrado: %d", numero);
    return 0;
}