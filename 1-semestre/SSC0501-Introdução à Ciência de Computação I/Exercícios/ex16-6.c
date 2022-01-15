#include <stdio.h>
#include <stdlib.h>

struct carro {
    char modelo[21], cor[16];
   float preco;
};

int main() {
    struct carro c[5];
    FILE *arq;

    arq = fopen("carro.txt", "rb+");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(0);
    }

    fread(c, sizeof(struct carro), 5, arq);

    for (int i = 0; i < 5; i++) {
        if (c[i].preco > 20000) {
            printf("%s %s %f\n", c[i].modelo, c[i].cor, c[i].preco);
        }
    }
}