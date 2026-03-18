#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int vetor[], int inicio, int fim, int valor)
{
    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    system("chcp 65001 > nul");
    int tamanho = 10;
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int valorProcurado = 11;

    int resultado = buscaBinaria(vetor, 0, tamanho - 1, valorProcurado);

    if (resultado != -1)
        printf("Valor %d encontrado no índice %d.\n", valorProcurado, resultado);
    else
        printf("Valor %d não encontrado no vetor.\n", valorProcurado);

    return 0;
}