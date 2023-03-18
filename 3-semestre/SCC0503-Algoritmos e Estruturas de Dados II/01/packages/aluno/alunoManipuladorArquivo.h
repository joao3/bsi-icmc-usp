#ifndef ALUNO_MANIPULADOR_ARQUIVO_H
#define ALUNO_MANIPULADOR_ARQUIVO_H

#include <stdio.h>

#include "aluno.h"

FILE * arquivo_abrir(char *nome_arquivo, char *modo);
void arquivo_fechar(FILE *file_pointer);
void arquivo_deslocar_nposicoes(FILE *file_pointer, int n);
void arquivo_ler_proximo_aluno(FILE *file_pointer, ALUNO *aluno);
void arquivo_escrever_aluno(FILE *file_pointer, ALUNO *aluno);
int arquivo_quantidade_alunos(FILE *file_pointer);

#endif //ALUNO_MANIPULADOR_ARQUIVO_H