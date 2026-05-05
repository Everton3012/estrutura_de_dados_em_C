#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct
{
    char nome[30];
    int idade;
} Pessoa;

typedef struct
{
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

void inicializarFila(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filaCheia(Fila *f)
{
    return f->total == MAX;
}

int filaVazia(Fila *f)
{
    return f->total == 0;
}

void inserir(Fila *f, Pessoa p)
{
    if (filaCheia(f))
    {
        printf("Fila Cheia. Não é possivel inserir.\n");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

void remover(Fila *f, Pessoa *p)
{
    if (filaVazia(f))
    {
        printf("Fila vazia. Não é possivel remover.\n");
        return;
    }

    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
}

void mostrarFila(Fila *f){
    printf("Fila: ");
    for(int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX)
    {
        printf("[%s, %d] ",
        f->itens[idx].nome,
        f->itens[idx].idade);
    }
    printf("\n");
}

int main()
{
    Fila f;
    inicializarFila(&f); //inicializa a fila

    //Isere algumas pessoas na fila
    Pessoa p1 = {"Alice", 30};
    Pessoa p2 = {"Bob", 25};
    Pessoa p3 = {"Charlie", 35};
    inserir(&f, p1);
    inserir(&f, p2);
    mostrarFila(&f);
    inserir(&f, p3);
    mostrarFila(&f);
    Pessoa removida;
    remover(&f, &removida);
    printf("Pessoa removida: %s, %d\n", removida.nome, removida.idade);
    mostrarFila(&f);
    return 0;
}