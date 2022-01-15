#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq;
    int veta[5] = {2, 2, 3, 4, 5}, vetb[5];

    arq = fopen("ex16-4.txt", "wb+");
    if (arq == NULL) exit(0);

    fwrite(veta, sizeof(int), 5, arq);

    fseek(arq, 0, SEEK_SET);

    fread(vetb, sizeof(int), 5, arq);

    for (int i = 0; i < 5; i++) {
        printf("%d ", vetb[i]);
    }

    fclose(arq);
}