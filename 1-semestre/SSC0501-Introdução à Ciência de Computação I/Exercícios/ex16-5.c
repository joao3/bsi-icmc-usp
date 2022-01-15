#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carro {
    char modelo[21], cor[16];
    float preco;
};

int main() {
    struct carro c[5];

    strcpy(c[0].modelo, "AAAA"); strcpy(c[0].cor, "aaaa"); c[0].preco = 6000;
    strcpy(c[1].modelo, "BBBB"); strcpy(c[1].cor, "bbbb"); c[1].preco = 12000;
    strcpy(c[2].modelo, "CCCC"); strcpy(c[2].cor, "cccc"); c[2].preco = 18000;
    strcpy(c[3].modelo, "DDDD"); strcpy(c[3].cor, "dddd"); c[3].preco = 24000;
    strcpy(c[4].modelo, "EEEE"); strcpy(c[4].cor, "eeee"); c[4].preco = 30000;

    FILE *arq;

    arq = fopen("carro.txt", "wb+");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(0);
    }

    fwrite(c, sizeof(struct carro), 5, arq);

    fclose(arq);
}