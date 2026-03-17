#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    int valor;
    struct No *proximo;
} No;

void inserirNoInicio(struct No **inicio, int valor);
void exibirLista(struct No *inicio);
void liberarLista(struct No **inicio);
void removerDoInicio(struct No **inicio);
int buscaLinear(struct No *inicio, int valor);

int main()
{
    system("chcp 65001 > nul");
    struct No *lista = NULL;

    inserirNoInicio(&lista, 10);
    inserirNoInicio(&lista, 20);
    inserirNoInicio(&lista, 30);
    inserirNoInicio(&lista, 40);

    printf("Lista ligada:\n");
    exibirLista(lista);

    printf("\n--- Buscando elementos ---\n");
    int valor1 = 20;
    int resultado1 = buscaLinear(lista, valor1);
    if (resultado1)
        printf("Elemento %d encontrado!\n", valor1);
    else
        printf("Elemento %d NÃO encontrado.\n", valor1);

    int valor2 = 50;
    int resultado2 = buscaLinear(lista, valor2);
    if (resultado2)
        printf("Elemento %d encontrado!\n", valor2);
    else
        printf("Elemento %d NÃO encontrado.\n", valor2);

    printf("\nRemovendo o primeiro nó...\n");
    removerDoInicio(&lista);

    printf("Lista após remoção:\n");
    exibirLista(lista);

    liberarLista(&lista);
    return 0;
}

void inserirNoInicio(struct No **inicio, int valor)
{
    struct No *novoNo = (struct No *)malloc(sizeof(struct No));
    if (novoNo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->valor = valor;
    novoNo->proximo = *inicio;
    *inicio = novoNo;
}

void exibirLista(struct No *inicio)
{
    struct No *atual = inicio;
    while (atual != NULL)
    {
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void liberarLista(struct No **inicio)
{
    struct No *atual = *inicio;
    while (atual != NULL)
    {
        struct No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    *inicio = NULL;
}

void removerDoInicio(struct No **inicio)
{
    if (*inicio == NULL)
    {
        printf("Lista vazia! Nada para remover.\n");
        return;
    }

    struct No *temp = *inicio;
    *inicio = (*inicio)->proximo;
    printf("Nó com valor %d removido.\n", temp->valor);
    free(temp);
}

int buscaLinear(struct No *inicio, int valor)
{
    struct No *atual = inicio;
    while (atual != NULL)
    {
        if (atual->valor == valor)
            return 1;
        atual = atual->proximo;
    }
    return 0;
}