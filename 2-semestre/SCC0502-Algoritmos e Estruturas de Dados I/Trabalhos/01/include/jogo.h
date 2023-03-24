#ifndef JOGO_H
#define JOGO_H

#define TAM_MAX_STRING 51
#define ERRO_JOGO 77777

typedef struct jogo_st JOGO;

JOGO * jogo_criar();
void jogo_definir_nome(JOGO *jogo, char *nome);
void jogo_definir_ano(JOGO *jogo, int ano);
void jogo_definir_produtora(JOGO *jogo, char *produtora);
char * jogo_pegar_nome(JOGO *jogo);
char * jogo_pegar_produtora(JOGO *jogo);
int jogo_pegar_ano(JOGO *jogo);
void jogo_destruir(JOGO **jogo);

#endif //JOGO_H