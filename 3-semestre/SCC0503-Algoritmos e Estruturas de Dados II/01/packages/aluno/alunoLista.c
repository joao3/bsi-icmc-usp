#include <stdlib.h>
#include <stdio.h>

#include "alunoLista.h"

struct aluno_lista_st
{
    ALUNO **alunos;
    int tamanho;
};

ALUNO_LISTA * aluno_lista_criar()
{
    ALUNO_LISTA *lista = malloc(1 * sizeof(ALUNO_LISTA));
    if (lista == NULL)
    {
        printf("Erro ao alocar lista de alunos\n");
        exit(-1);
    }
    lista->alunos = NULL;
    lista->tamanho = 0;
    return lista;
}

void aluno_lista_destruir(ALUNO_LISTA **lista)
{
    if (*lista != NULL)
    {
        for (int i = 0; i < (*lista)->tamanho; i++)
        {
            aluno_destruir(&((*lista)->alunos[i]));
        }
        free((*lista)->alunos);
        (*lista)->alunos = NULL;
        free(*lista);
        *lista = NULL;
    }
}

void aluno_lista_inserir(ALUNO_LISTA *lista, ALUNO *aluno)
{
    if (lista != NULL && aluno != NULL)
    {
        lista->alunos = realloc(lista->alunos, (lista->tamanho + 1) * sizeof(ALUNO *));
        lista->alunos[lista->tamanho] = aluno;
        lista->tamanho++;
    }
}

ALUNO * aluno_lista_pegar_iesimo(ALUNO_LISTA *lista, int i)
{
    if (lista != NULL)
    {
        if (i < 0 || i >= lista->tamanho)
        {
            printf("Indice invalido\n");
            return NULL;
        }
        return lista->alunos[i];
    }
    return NULL;
}

int aluno_lista_tamanho(ALUNO_LISTA *lista)
{
    if (lista != NULL)
    {
        return lista->tamanho;
    }
    return -1;
}