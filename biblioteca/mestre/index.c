#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

typedef struct
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
} Livro;

typedef struct
{
    int indiceLivro;
    char nomeUsuario[TAM_STRING];
} Emprestimo;

void limparBuffer();
void exibirMenu();
void cadastarLivro(Livro *biblioteca, int *totalLivros);
void listarLivros(const Livro *biblioteca, int totalLivros);
void realizarEmprestimo(Livro *biblioteca, Emprestimo *emprestimos, int totalLivros, int *totalEmprestimos);
void listarEmprestimos(Livro *biblioteca, Emprestimo *emprestimos, int totalEmprestimos);
void liberarMemoria(Livro *biblioteca, Emprestimo *emprestimos);

int main()
{
    system("chcp 65001 > nul");

    Livro *biblioteca = (Livro *)calloc(MAX_LIVROS, sizeof(Livro));

    Emprestimo *emprestimos = (Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(Emprestimo));

    if (biblioteca == NULL || emprestimos == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;
    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            cadastarLivro(biblioteca, &totalLivros);
            break;
        case 2:
            listarLivros(biblioteca, totalLivros);
            break;
        case 3:
            realizarEmprestimo(biblioteca, emprestimos, totalLivros, &totalEmprestimos);
            break;
        case 4:
            listarEmprestimos(biblioteca, emprestimos, totalEmprestimos);
            break;
        case 0:
            printf("Saindo da biblioteca. Até logo!\n");
            break;
        default:
            printf("Opção inválida. Por favor, tente novamente.\n");
            printf("\nPressione Enter para continuar...");
            getchar();
        }
    } while (opcao != 0);

    liberarMemoria(biblioteca, emprestimos);

    printf("Memória liberada. Encerrando programa.\n");

    return 0;
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void exibirMenu()
{
    printf("==========================================\n");
    printf("Bem-vindo à Biblioteca\n");
    printf("==========================================\n");
    printf("1. Cadastrar livro\n");
    printf("2. Listar livros\n");
    printf("3. Emprestar livro\n");
    printf("4. Listar livros emprestados\n");
    printf("0. Sair\n");
    printf("------------------------------------------\n");
    printf("Escolha uma opção: ");
}

void cadastarLivro(Livro *biblioteca, int *totalLivros)
{
    printf("==========================================\n");
    printf("Cadastrar Livro\n");
    printf("------------------------------------------\n");
    if (*totalLivros < MAX_LIVROS)
    {
        printf("Digite o nome do livro: ");
        fgets(biblioteca[*totalLivros].nome, TAM_STRING, stdin);
        biblioteca[*totalLivros].nome[strcspn(biblioteca[*totalLivros].nome, "\n")] = '\0';

        printf("Digite o autor do livro: ");
        fgets(biblioteca[*totalLivros].autor, TAM_STRING, stdin);
        biblioteca[*totalLivros].autor[strcspn(biblioteca[*totalLivros].autor, "\n")] = '\0';

        printf("Digite a editora do livro: ");
        fgets(biblioteca[*totalLivros].editora, TAM_STRING, stdin);
        biblioteca[*totalLivros].editora[strcspn(biblioteca[*totalLivros].editora, "\n")] = '\0';

        printf("Digite a edição do livro: ");
        scanf("%d", &biblioteca[*totalLivros].edicao);
        limparBuffer();
        biblioteca[*totalLivros].disponivel = 1;
        (*totalLivros)++; // ✅ incrementa o VALOR, não o ponteiro
        printf("Livro cadastrado com sucesso!\n");
    }
    else
    {
        printf("Capacidade máxima de livros atingida.\n");
    }
}

void listarLivros(const Livro *biblioteca, int totalLivros)
{
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
    printf("\nPressione Enter para continuar...");
    getchar();
}

void realizarEmprestimo(Livro *biblioteca, Emprestimo *emprestimos, int totalLivros, int *totalEmprestimos)
{
    printf("--- Realizar Emprestimo ---\n\n");

    if (*totalEmprestimos >= MAX_EMPRESTIMOS)
    {
        printf("Limite de empréstimos atingido.\n");
    }
    else
    {
        printf("Livros disponíveis para empréstimo:\n");
        int disponiveis = 0;
        for (int i = 0; i < totalLivros; i++)
        {
            if (biblioteca[i].disponivel)
            {
                printf("%d - %s\n", i + 1, biblioteca[i].nome);
                disponiveis++;
            }
        }

        if (disponiveis == 0)
        {
            printf("Nenhum livro disponível para empréstimo.\n");
        }
        else
        {
            printf("\nDigite o número do livro que deseja emprestar: ");
            int numLivro;
            scanf("%d", &numLivro);
            limparBuffer();

            int indiceLivro = numLivro - 1;
            if (indiceLivro >= 0 && indiceLivro < totalLivros && biblioteca[indiceLivro].disponivel)
            {
                printf("Digite o nome do usuario: ");
                fgets(emprestimos[*totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                emprestimos[*totalEmprestimos].nomeUsuario[strcspn(emprestimos[*totalEmprestimos].nomeUsuario, "\n")] = '\0';

                emprestimos[*totalEmprestimos].indiceLivro = indiceLivro;
                biblioteca[indiceLivro].disponivel = 0;

                (*totalEmprestimos)++;
                printf("\nEmpréstimo realizado com sucesso!\n");
            }
            else
            {
                printf("Número inválido ou livro indisponível.\n");
            }
        }
    }
    printf("\nPressione Enter para continuar...");
    getchar();
}

void listarEmprestimos(Livro *biblioteca, Emprestimo *emprestimos, int totalEmprestimos)
{
    printf("--- Lista de Emprestimos ---\n\n");
    if (totalEmprestimos == 0)
    {
        printf("Nenhum emprestimo realizado.\n");
    }
    else
    {
        for (int i = 0; i < totalEmprestimos; i++)
        {
            int indiceLivro = emprestimos[i].indiceLivro;
            printf("------------------------------------------\n");
            printf("Emprestimo %d:\n", i + 1);
            printf("Livro: %s\n", biblioteca[indiceLivro].nome);
            printf("Usuario: %s\n", emprestimos[i].nomeUsuario);
        }
    }
}

void liberarMemoria(Livro *biblioteca, Emprestimo *emprestimos)
{
    free(biblioteca);
    free(emprestimos);
}