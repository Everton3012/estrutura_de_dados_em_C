#include <stdio.h>

typedef struct
{
    char nome[50];
    int idade;
    float nota;
} Aluno;


int main () {
    Aluno a1 = {"João", 20, 8.5};

    printf("Nome: %s\n", a1.nome);
    printf("Idade: %d\n", a1.idade);
    printf("Nota: %.2f\n", a1.nota);

    return 0;
};