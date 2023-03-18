#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "aluno.h"

struct aluno_st
{
    int nUSP;
    char nome[TAMANHO_STRING];
    char curso[TAMANHO_STRING];
    float nota;
};

ALUNO * aluno_criar()
{
    ALUNO *aluno = (ALUNO *) malloc(1 * sizeof(ALUNO));
    if (aluno == NULL)
    {
        printf("Erro ao alocar aluno");
        exit(-1);
    }
    memset(aluno->curso, 0, TAMANHO_STRING);
    memset(aluno->nome, 0, TAMANHO_STRING);
    return aluno;
}

void aluno_destruir(ALUNO **aluno)
{
    if (*aluno != NULL)
    {
        free(*aluno);
        *aluno = NULL;
    }
}

void aluno_imprimir(ALUNO *aluno)
{
    if (aluno != NULL)
    {
        printf("nUSP: %d\n", aluno->nUSP);
        printf("Nome: %s\n", aluno->nome);
        printf("Curso: %s\n", aluno->curso);
        printf("Nota: %.2f\n", aluno->nota);
    }
}

void aluno_definir_nUSP(ALUNO *aluno, int nUSP)
{
    if (aluno != NULL)
    {
        aluno->nUSP = nUSP;
    }
}

void aluno_definir_nome(ALUNO *aluno, char *nome)
{
    if (aluno != NULL)
    {
        strcpy(aluno->nome, nome);
    }
}

void aluno_definir_curso(ALUNO *aluno, char *curso)
{
    if (aluno != NULL)
    {
        strcpy(aluno->curso, curso);
    }

}
void aluno_definir_nota(ALUNO *aluno, float nota)
{
    if (aluno != NULL)
    {
        aluno->nota = nota;
    }
}

int aluno_pegar_nUSP(ALUNO *aluno)
{
    if (aluno != NULL)
    {
        return aluno->nUSP;
    }
    return -1;
}

char * aluno_pegar_nome(ALUNO *aluno)
{
    if (aluno != NULL)
    {
        return aluno->nome;
    }
    return NULL;
}

char * aluno_pegar_curso(ALUNO *aluno)
{
    if (aluno != NULL)
    {
        return aluno->curso;
    }
    return NULL;
}

float aluno_pegar_nota(ALUNO *aluno)
{
    if (aluno != NULL)
    {
        return aluno->nota;
    }
    return -1;
}

int sizeof_aluno()
{
    return sizeof(ALUNO);
}