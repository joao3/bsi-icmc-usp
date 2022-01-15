#include <stdio.h>
#include <string.h>

struct aluno {
    char nome[31]; 
    int nUSP;
    float media;
};

void divide(struct aluno *vet, struct aluno *ap, struct aluno *re, int *cAp, int *cRe) {
    for (int i = 0; i < 10; i++) {
        if (vet[i].media >= 5) {
            strcpy(ap[*cAp].nome, vet[i].nome); ap[*cAp].nUSP = vet[i].nUSP; ap[*cAp].media = vet[i].media;
            (*cAp)++;
        } else {
            strcpy(re[*cRe].nome, vet[i].nome); re[*cRe].nUSP = vet[i].nUSP; re[*cRe].media = vet[i].media;
            (*cRe)++;
        }
    }
}

int main() {
    struct aluno a[10];
    strcpy(a[0].nome, "AAAA"); a[0].nUSP = 0000; a[0].media = 10;
    strcpy(a[1].nome, "BBBB"); a[1].nUSP = 1111; a[1].media = 5;
    strcpy(a[2].nome, "CCCC"); a[2].nUSP = 2222; a[2].media = 6;
    strcpy(a[3].nome, "DDDD"); a[3].nUSP = 3333; a[3].media = 4;
    strcpy(a[4].nome, "EEEE"); a[4].nUSP = 4444; a[4].media = 3;
    strcpy(a[5].nome, "FFFF"); a[5].nUSP = 5555; a[5].media = 8;
    strcpy(a[6].nome, "GGGG"); a[6].nUSP = 6666; a[6].media = 2;
    strcpy(a[7].nome, "HHHH"); a[7].nUSP = 7777; a[7].media = 0;
    strcpy(a[8].nome, "IIII"); a[8].nUSP = 8888; a[8].media = 9;
    strcpy(a[9].nome, "JJJJ"); a[9].nUSP = 9999; a[9].media = 7;

    struct aluno aprovados[10], reprovados[10];
    int countAp = 0, countRe = 0;

    divide(a, aprovados, reprovados, &countAp, &countRe);

    printf("Aprovados:\n");
    for (int i = 0; i < countAp; i++) {
        printf("%s %d %f\n", aprovados[i].nome, aprovados[i].nUSP, aprovados[i].media);
    }

    printf("Reprovados:\n");
    for (int i = 0; i < countRe; i++) {
        printf("%s %d %f\n", reprovados[i].nome, reprovados[i].nUSP, reprovados[i].media);
    }
}