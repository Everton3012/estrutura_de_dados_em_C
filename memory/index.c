#include <stdio.h>
#include <stdlib.h>

int main()
{
     system("chcp 65001 > nul"); 
     
    int *a, b;

    b = 10;
    a = (int *)malloc(sizeof(int));
    *a = 20;
    printf("Valor de a: %d\n", *a);
    free(a);
    printf("Valor de a apos free: %d\n", *a);
    // Acessar a memória após liberar pode causar comportamento indefinido
    a = NULL;
    if (a == NULL)
        printf("a está NULL, não pode acessar *a\n");
    a = &b;
    printf("Valor de a agora aponta para b: %d\n", *a);

    return 0;
}