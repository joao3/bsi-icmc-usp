#ifndef CAMINHO_H
#define CAMINHO_H

typedef struct caminho_st CAMINHO;

CAMINHO * cria_caminho();
void le_caminho(CAMINHO *caminho);
float calcula_distancia_total(CAMINHO *caminho);
void exclui_caminho(CAMINHO *caminho);

#endif