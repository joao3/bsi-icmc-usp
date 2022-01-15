#include <stdio.h>

int main() {
    int notasaltas = 0, notasbaixas = 0;
    float nota = 0, mediageral = 0, porcnotas_altas = 0, total = 0;

    while (1) {
        scanf("%f", &nota);
        if (nota < 0) break;
        if (nota >= 5) notasaltas++; else notasbaixas++;
        total += nota;       
    }

    mediageral = total/(notasaltas + notasbaixas);
    porcnotas_altas = ((notasaltas * 1.0)/(notasbaixas + notasaltas)) * 100;

    printf("%d %d %f %f", notasaltas, notasbaixas, mediageral, porcnotas_altas);
}
