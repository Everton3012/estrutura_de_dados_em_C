#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int iteracoes_binaria = 0;
int iteracoes_linear = 0;

int buscaBinaria(int vetor[], int inicio, int fim, int valor)
{
    while (inicio <= fim)
    {
        iteracoes_binaria++;
        int meio = inicio + (fim - inicio) / 2;

        printf("Iteração %d: início=%d, fim=%d, meio=%d, vetor[meio]=%d\n", 
               iteracoes_binaria, inicio, fim, meio, vetor[meio]);

        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int buscaLinear(int vetor[], int tamanho, int valor)
{
    for (int i = 0; i < tamanho; i++)
    {
        iteracoes_linear++;
        
        // Print a cada 100mil iterações para não travar
        if (iteracoes_linear % 100000 == 0)
            printf("Iteração %d: vetor[%d]=%d\n", iteracoes_linear, i, vetor[i]);

        if (vetor[i] == valor)
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    system("chcp 65001 > nul");

    // Criar vetor GRANDE com 1 MILHÃO de elementos
    int tamanho = 1000000;
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    // Preencher com números pares
    for (int i = 0; i < tamanho; i++)
        vetor[i] = i * 2;

    int valorProcurado = 999998;  // Perto do final

    printf("Tamanho do vetor: %d elementos\n", tamanho);
    printf("Procurando o valor: %d\n\n", valorProcurado);

    // ===== BUSCA LINEAR =====
    printf("========== BUSCA LINEAR ==========\n");
    iteracoes_linear = 0;
    clock_t inicio_linear = clock();
    int resultado_linear = buscaLinear(vetor, tamanho, valorProcurado);
    clock_t fim_linear = clock();

    double tempo_linear = (double)(fim_linear - inicio_linear) / CLOCKS_PER_SEC * 1000;

    printf("\n");
    if (resultado_linear != -1)
        printf("✓ Valor %d encontrado no índice %d.\n", valorProcurado, resultado_linear);
    else
        printf("✗ Valor %d não encontrado no vetor.\n", valorProcurado);
    printf("Iterações: %d\n", iteracoes_linear);
    printf("Tempo: %.4f ms\n\n", tempo_linear);

    // ===== BUSCA BINÁRIA =====
    printf("========== BUSCA BINÁRIA ==========\n");
    iteracoes_binaria = 0;
    clock_t inicio_binaria = clock();
    int resultado_binaria = buscaBinaria(vetor, 0, tamanho - 1, valorProcurado);
    clock_t fim_binaria = clock();

    double tempo_binaria = (double)(fim_binaria - inicio_binaria) / CLOCKS_PER_SEC * 1000;

    printf("\n");
    if (resultado_binaria != -1)
        printf("✓ Valor %d encontrado no índice %d.\n", valorProcurado, resultado_binaria);
    else
        printf("✗ Valor %d não encontrado no vetor.\n", valorProcurado);
    printf("Iterações: %d\n", iteracoes_binaria);
    printf("Tempo: %.4f ms\n\n", tempo_binaria);

    // ===== COMPARAÇÃO =====
    printf("========== COMPARAÇÃO ==========\n");
    printf("Busca Linear:\n");
    printf("  - Iterações: %d\n", iteracoes_linear);
    printf("  - Tempo: %.4f ms\n\n", tempo_linear);
    
    printf("Busca Binária:\n");
    printf("  - Iterações: %d\n", iteracoes_binaria);
    printf("  - Tempo: %.4f ms\n\n", tempo_binaria);
    
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    
    if (tempo_linear > tempo_binaria)
    {
        printf("Busca Binária foi %.2fx MAIS RÁPIDA!\n", tempo_linear / tempo_binaria);
        printf("Economizou %d iterações!\n", iteracoes_linear - iteracoes_binaria);
    }
    else
    {
        printf("Busca Linear foi %.2fx MAIS RÁPIDA!\n", tempo_binaria / tempo_linear);
    }

    free(vetor);
    return 0;
}