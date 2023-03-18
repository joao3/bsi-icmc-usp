#include <stdio.h>
#include <stdlib.h>

#include "alunoManipuladorArquivo.h"

FILE * arquivo_abrir(char *nome_arquivo, char *modo)
{
    if (nome_arquivo != NULL)
    {
        FILE *file_pointer = fopen(nome_arquivo, modo);
        if (file_pointer == NULL)
        {
            printf("Erro ao abrir o arquivo: %s\n", nome_arquivo);
            exit(-1);
        }
        return file_pointer;
    }
    return NULL;
}

void arquivo_fechar(FILE *file_pointer)
{
    fclose(file_pointer);
}

void arquivo_ler_proximo_aluno(FILE *file_pointer, ALUNO *aluno)
{
    if (file_pointer != NULL && aluno != NULL)
    {
        int nUSP;
        fread(&nUSP, sizeof(int), 1, file_pointer);

        char nome[TAMANHO_STRING];
        fread(nome, sizeof(char), TAMANHO_STRING, file_pointer);

        char curso[TAMANHO_STRING];
        fread(curso, sizeof(char), TAMANHO_STRING, file_pointer);

        float nota;
        fread(&nota, sizeof(float), 1, file_pointer);

        aluno_definir_nUSP(aluno, nUSP);
        aluno_definir_nome(aluno, nome);
        aluno_definir_curso(aluno, curso);
        aluno_definir_nota(aluno, nota);
    }
}

void arquivo_escrever_aluno(FILE *file_pointer, ALUNO *aluno)
{
    if (file_pointer != NULL && aluno != NULL)
    {
        int nUSP = aluno_pegar_nUSP(aluno);
        fwrite(&nUSP, sizeof(int), 1, file_pointer);

        char *nome = aluno_pegar_nome(aluno);
        fwrite(nome, sizeof(char), TAMANHO_STRING, file_pointer);

        char *curso = aluno_pegar_curso(aluno);
        fwrite(curso, sizeof(char), TAMANHO_STRING, file_pointer);

        float nota = aluno_pegar_nota(aluno);
        fwrite(&nota, sizeof(float), 1, file_pointer);
    }
}

int arquivo_quantidade_alunos(FILE *file_pointer)
{
    if (file_pointer != NULL)
    {
        fseek(file_pointer, 0, SEEK_END);
        int n = ftell(file_pointer) / sizeof_aluno();
        fseek(file_pointer, 0, SEEK_SET);
        return n;
    }
    return -1;
}

void arquivo_deslocar_nposicoes(FILE *file_pointer, int n)
{
    if (file_pointer != NULL)
    {
        fseek(file_pointer, n * sizeof_aluno(), SEEK_SET);
    }
}