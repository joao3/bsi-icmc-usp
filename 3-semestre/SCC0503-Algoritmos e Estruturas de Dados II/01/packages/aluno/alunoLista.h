#ifndef ALUNO_LISTA_H
#define ALUNO_LISTA_H

#include "aluno.h"

typedef struct aluno_lista_st ALUNO_LISTA;

ALUNO_LISTA * aluno_lista_criar();
void aluno_lista_destruir(ALUNO_LISTA **lista);
void aluno_lista_inserir(ALUNO_LISTA *lista, ALUNO *aluno);
ALUNO * aluno_lista_pegar_iesimo(ALUNO_LISTA *lista, int i);
int aluno_lista_tamanho(ALUNO_LISTA *lista);

#endif //ALUNO_LISTA_H