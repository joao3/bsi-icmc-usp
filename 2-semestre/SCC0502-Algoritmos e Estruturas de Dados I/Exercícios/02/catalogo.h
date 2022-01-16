#ifndef CATALOGO_H
#define CATALOGO_H

typedef struct catalogo_st CATALOGO;

CATALOGO * catalogo_criar();
void catalogo_ler(CATALOGO *catalogo);
void catalogo_inserir_jogo(CATALOGO *catalogo, char nome[], char produtora[], int ano);
void catalogo_buscas(CATALOGO *catalogo, char operacao);
void catalogo_excluir(CATALOGO **catalogo);

#endif //CATALOGO_H