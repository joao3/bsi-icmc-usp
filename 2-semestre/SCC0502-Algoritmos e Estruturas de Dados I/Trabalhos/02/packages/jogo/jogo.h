#ifndef JOGO_H
#define JOGO_H

#include "../util/utilBoolean.h"

#define JOGO_TAMANHO_STRING 51
#define ERRO_JOGO 77777

typedef struct jogo_st JOGO;

JOGO * jogo_criar();
void jogo_definir_nome(JOGO *jogo, char *nome);
void jogo_definir_ano(JOGO *jogo, int ano);
void jogo_definir_produtora(JOGO *jogo, char *produtora);
char * jogo_pegar_nome(JOGO *jogo);
char * jogo_pegar_produtora(JOGO *jogo);
int jogo_pegar_ano(JOGO *jogo);
void jogo_destruir(void **jogo);
boolean jogo_nome_eh_maior(JOGO *jogo1, JOGO *jogo2);
boolean jogo_chave_eh_maior(void *jogo1, void *jogo2);
boolean jogo_ano_eh_maior(void *jogo1, void *jogo2);
boolean jogo_ano_eh_maior_campo(void *jogo1, void *ano);
boolean jogo_ano_eh_igual(void *jogo1, void *jogo2);
boolean jogo_ano_eh_igual_campo(void *jogo1, void *ano);
void jogo_imprimir_nome(void *jogo);

/*
 *  jogo_nome_eh_maior:
 *      Retorna 1 se jogo1->nome vir antes na ordem alfabética que jogo2->nome
 *      Senao retorna 0
 *
 *  jogo_chave_eh_maior:
 *      Se jogo1->ano < jogo2->ano retorna 1
 *      Se jogo1->ano > jogo2->ano retorna 0
 *      Senao retorna jogo_nome_eh_maior
 *
 *  jogo_ano_eh_maior:
 *      Retorna 1 se jogo1->ano > jogo2->ano
 *      Senao retorna 0
 *
 *  jogo_ano_eh_maior_campo:
 *      Retorna 1 se jogo1->ano > ano
 *      Senao retorna 0
 *      Ou seja, compara jogo1 com um campo ano e não com outro jogo
 *
 *  jogo_ano_eh_igual e jogo_ano_eh_igual_campo:
 *      Funcionam analogamente as funções jogo_ano_eh_maior e jogo_ano_eh_maior_campo
 */

#endif //JOGO_H