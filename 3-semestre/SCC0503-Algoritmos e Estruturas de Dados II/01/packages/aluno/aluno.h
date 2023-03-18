#ifndef ALUNO_H
#define ALUNO_H

#define TAMANHO_STRING 50

typedef struct aluno_st ALUNO;

ALUNO * aluno_criar();
void aluno_destruir(ALUNO **);
void aluno_imprimir(ALUNO *aluno);
void aluno_definir_nUSP(ALUNO *aluno, int nUSP);
void aluno_definir_nome(ALUNO *aluno, char *nome);
void aluno_definir_curso(ALUNO *aluno, char *curso);
void aluno_definir_nota(ALUNO *aluno, float nota);
int aluno_pegar_nUSP(ALUNO *aluno);
char * aluno_pegar_nome(ALUNO *aluno);
char * aluno_pegar_curso(ALUNO *aluno);
float aluno_pegar_nota(ALUNO *aluno);
int sizeof_aluno();

#endif //ALUNO_H