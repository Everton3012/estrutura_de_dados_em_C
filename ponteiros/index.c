#include <stdio.h>

int main()
{
    int a = 10;
    int *p = &a;

    printf("Valor de a: %d\n", a);
    printf("Endereco de a: %p\n", &a);
    printf("Valor de p: %p\n", p);
    printf("Valor apontado por p: %d\n", *p);

    printf("\nModificando o valor de a usando o ponteiro p...\n");

    *p = 20;
    printf("Valor de a apos modificacao: %d\n", a);
    printf("Endereco de a: %p\n", &a);
    printf("Valor de p: %p\n", p);
    printf("Valor apontado por p: %d\n", *p);
    return 0;
}