#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq;
    char p[21], pArq[21];
    int count = 0;

    arq = fopen("arquivo2.txt", "r+");
    if (arq == NULL) exit(0);

    scanf("%s", p);

    while (!feof(arq)) {
        fscanf(arq, "%s\n", pArq);
        size_t len = strlen(pArq);
        size_t lenP = strlen(p);
        for (int i = 0; i < len; i++) {
            if (pArq[i] == p[0]) {
                int auxP = 0, auxParq = i, aux = 0;
                while (1) {
                    if (p[auxP] != pArq[auxParq] && p[auxP] != '\0') break;
                    if (aux == lenP) {
                        count++;
                        break;
                    }
                    aux++;
                    auxP++;
                    auxParq++;
                }
            }
        }
    }

    printf("%d", count);

    fclose(arq);
}