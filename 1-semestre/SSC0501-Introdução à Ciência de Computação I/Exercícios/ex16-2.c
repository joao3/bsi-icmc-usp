#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *arq;
    char pal[16], str[16];

    arq = fopen("ex16-2.txt", "r+");
    if (arq == NULL) exit(0);
    
    scanf("%s", pal);

    while (!feof(arq)) {
        fscanf(arq, "%s", str);
        if (strcmp(str, pal) == 0) {
            printf("Palavra encontrada");
            exit(0);
        }
    }
    fclose(arq);
    printf("Palavra nao encontrada");
}