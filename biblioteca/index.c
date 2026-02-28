#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define TAM_STRING 100

typedef struct
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
} Livro;

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
};

int main()
{
    Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    do
    {
        printf("==========================================\n");
        printf("Bem-vindo à Biblioteca\n");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Sair\n");
        printf("------------------------------------------\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            printf("==========================================\n");
            printf("Cadastrar Livro\n");
            printf("------------------------------------------\n");
            if (totalLivros < MAX_LIVROS)
            {
                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';

                printf("Digite o autor do livro: ");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';

                printf("Digite a editora do livro: ");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                printf("Digite a edição do livro: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limparBuffer();

                totalLivros++;
                printf("Livro cadastrado com sucesso!\n");
            }
            else
            {
                printf("Capacidade máxima de livros atingida.\n");
            }
            break;
        case 2:
            printf("==========================================\n");
            printf("Lista de Livros\n");
            printf("------------------------------------------\n");
            if (totalLivros > 0)
            {
                for (int i = 0; i < totalLivros; i++)
                {
                    printf("Livro %d:\n", i + 1);
                    printf("Nome: %s\n", biblioteca[i].nome);
                    printf("Autor: %s\n", biblioteca[i].autor);
                    printf("Editora: %s\n", biblioteca[i].editora);
                    printf("Edição: %d\n", biblioteca[i].edicao);
                    printf("------------------------------------------\n");
                }
            }
            else
            {
                printf("Nenhum livro cadastrado.\n");
            }
            break;
        case 3: 
            printf("Saindo da biblioteca. Até logo!\n");
            break;
        }   
    } while (opcao != 3);
};