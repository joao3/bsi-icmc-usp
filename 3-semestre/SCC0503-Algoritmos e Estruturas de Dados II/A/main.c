#include <stdio.h>

#include "packages/aluno/aluno.h"
#include "packages/aluno/alunoManipuladorArquivo.h"

#define TAM_STRING 50

void operacoes(FILE *file_pointer, int quantidade_alunos);
void exibir_todos(FILE *file_pointer, int quantidade_alunos);
void exibir_comeco_ao_meio(FILE *file_pointer, int quantidade_alunos);
void exibir_meio_ao_fim(FILE *file_pointer, int quantidade_alunos);
void exibir_faixa(FILE *file_pointer, int quantidade_alunos);
void exibir_especifico(FILE *file_pointer);

int main()
{
    char nome_arquivo[TAM_STRING];
    scanf("%s", nome_arquivo);

    FILE *file_pointer = arquivo_abrir(nome_arquivo, "rb");
    int quantidade_alunos = arquivo_quantidade_alunos(file_pointer);

    operacoes(file_pointer, quantidade_alunos);

    arquivo_fechar(file_pointer);
}

void operacoes(FILE *file_pointer, int quantidade_alunos)
{
    int operacao;
    scanf("%d", &operacao);

    switch (operacao)
    {
        case 1:
            exibir_todos(file_pointer, quantidade_alunos);
            break;

        case 2:
            exibir_comeco_ao_meio(file_pointer, quantidade_alunos);
            break;

        case 3:
            exibir_meio_ao_fim(file_pointer, quantidade_alunos);
            break;

        case 4:
            exibir_faixa(file_pointer, quantidade_alunos);
            break;

        case 5:
            exibir_especifico(file_pointer);
            break;

        default:
            printf("Operacao desconhecida\n");
    }
}

void exibir_todos(FILE *file_pointer, int quantidade_alunos)
{
    for (int i = 0; i < quantidade_alunos; i++)
    {
        ALUNO *aluno = aluno_criar();
        arquivo_ler_proximo_aluno(file_pointer, aluno);
        aluno_imprimir(aluno);
        if (i != quantidade_alunos - 1)
        {
            printf("\n");
        }
        aluno_destruir(&aluno);
    }
}

void exibir_comeco_ao_meio(FILE *file_pointer, int quantidade_alunos)
{
    for (int i = 0; i < quantidade_alunos / 2; i++)
    {
        ALUNO *aluno = aluno_criar();
        arquivo_ler_proximo_aluno(file_pointer, aluno);
        aluno_imprimir(aluno);
        if (i != quantidade_alunos / 2 - 1)
        {
            printf("\n");
        }
        aluno_destruir(&aluno);
    }
}

void exibir_meio_ao_fim(FILE *file_pointer, int quantidade_alunos)
{
    arquivo_deslocar_nposicoes(file_pointer, quantidade_alunos / 2);
    for (int i = quantidade_alunos / 2; i < quantidade_alunos; i++)
    {
        ALUNO *aluno = aluno_criar();
        arquivo_ler_proximo_aluno(file_pointer, aluno);
        aluno_imprimir(aluno);
        if (i != quantidade_alunos - 1)
        {
            printf("\n");
        }
        aluno_destruir(&aluno);
    }
}

void exibir_faixa(FILE *file_pointer, int quantidade_alunos)
{
    int inicio, final;
    scanf("%d %d", &inicio, &final);

    arquivo_deslocar_nposicoes(file_pointer, inicio - 1);
    for (int i = inicio - 1; i < final && i < quantidade_alunos; i++)
    {
        ALUNO *aluno = aluno_criar();
        arquivo_ler_proximo_aluno(file_pointer, aluno);
        aluno_imprimir(aluno);
        if (i != final - 1 && i != quantidade_alunos - 1)
        {
            printf("\n");
        }
        aluno_destruir(&aluno);
    }
}

void exibir_especifico(FILE *file_pointer)
{
    int posicao;
    scanf("%d", &posicao);

    arquivo_deslocar_nposicoes(file_pointer, posicao - 1);
    ALUNO *aluno = aluno_criar();
    arquivo_ler_proximo_aluno(file_pointer, aluno);
    aluno_imprimir(aluno);
    aluno_destruir(&aluno);
}