#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bolha(int vetor[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int sentinela, ultima_troca, trocou = 0;
        if (i == 0)
        {
            sentinela = n - 1;
        }
        for (int j = 0; j < sentinela; j++)
        {
            printf("C %d %d\n", j, j + 1);
            if (vetor[j] > vetor[j + 1])
            {
                trocou = 1;
                ultima_troca = j;
                printf("T %d %d\n", j, j + 1);
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
        if (trocou == 0)
        {
            break;
        }
        sentinela = ultima_troca;
    }
}

void selecao(int vetor[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < n; j++)
        {
            printf("C %d %d\n", menor, j);
            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }
        if (menor != i)
        {
            int temp = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = temp;
            printf("T %d %d\n", i, menor);
        }
    }
    
}

int main()
{
    char metodo[10];
    fgets(metodo, 10, stdin);

    int n;
    scanf("%d", &n);
    int *vetor = (int *) malloc(sizeof(int) * n);
    if (vetor == NULL)
    {
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    if (strcmp(metodo, "bolha\n") == 0)
    {
        bolha(vetor, n);
    }
    else if (strcmp(metodo, "selecao\n") == 0)
    {
        selecao(vetor, n);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
}