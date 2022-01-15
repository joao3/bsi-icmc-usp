#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char pal[21], palArq[21];
    FILE *arq;
    int count = 0;

    arq = fopen("arquivo.txt", "r+");
    if (arq == NULL) exit(0);

    scanf("%s", pal);

    while (!feof(arq)) {
        fscanf(arq, "%s", palArq);
        if (!strcmp(pal, palArq)) count++;
    }
    fclose(arq);

    printf("%d", count);
}