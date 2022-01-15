#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    char nome[31];
    float n1, n2, m;
};

int main() {
    FILE *arq;
    struct aluno a[5];

    arq = fopen("3.txt", "w+");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(0);
    }

    for (int i = 0; i < 5; i++) {
        printf("Aluno %d\n", i+1);
        printf("Nome: ");
        fgets(a[i].nome, 30, stdin);
        printf("Nota 1: ");
        scanf("%f", &a[i].n1);
        getchar();
        printf("Nota 2: ");
        scanf("%f", &a[i].n2);
        getchar();

        a[i].m = (a[i].n1 + a[i].n2)/2;

        printf("-------------------------\n");

        fprintf(arq, "%s%.2f\n%.2f\n%.2f\n", a[i].nome, a[i].n1, a[i].n2, a[i].m);
    }   

    fclose(arq);
}