#include <stdio.h>

#include "caminho.h"

int main()
{
    CAMINHO *caminho = cria_caminho();
    le_caminho(caminho);

    float distancia_total = calcula_distancia_total(caminho);

    exclui_caminho(caminho);

    printf("%.2f\n", distancia_total);
}