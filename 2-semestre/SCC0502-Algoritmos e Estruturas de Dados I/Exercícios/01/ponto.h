#ifndef PONTO_H
#define PONTO_H

typedef struct ponto_st PONTO;

PONTO * aloca_pontos(int quantidade_pontos);
void le_ponto(PONTO *pontos, int i);
float calcula_distancia_pontos(PONTO *pontos, int i);
void desaloca_pontos(PONTO *pontos);

#endif