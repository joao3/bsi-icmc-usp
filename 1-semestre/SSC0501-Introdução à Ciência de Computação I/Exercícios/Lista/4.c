#include <stdio.h>
#include <stdlib.h>

struct aluno {
    char nome[31];
    float n1, n2, m;
};

int main() {
    FILE *arq;
    float sum = 0;

    arq = fopen("3.txt", "r+");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(0);
    }

    for (int i = 0; i < 20; i++) {
        if (i == 0 || i == 4 || i == 8 || i == 12 || i == 16) {
            char temp[31];
            fscanf(arq, "%s", temp);
            printf("Aluno: %s\n", temp);
        } else if (i == 1 || i == 5 || i == 9 || i == 13 || i == 17) {
            float temp;
            fscanf(arq, "%f", &temp);
            printf("Nota 1: %f\n", temp);
        } else if (i == 2 || i == 6 || i == 10 || i == 14 || i == 18) {
            float temp;
            fscanf(arq, "%f", &temp);
            printf("Nota 2: %f\n", temp);
        } else if (i == 3 || i == 7 || i == 11 || i == 15 || i == 19) {
            float temp;
            fscanf(arq, "%f", &temp);
            printf("Media: %f\n", temp);
            sum += temp;
            printf("-----------------------------\n");       
        }
    }

    printf("Media da sala: %f", sum/5);
}