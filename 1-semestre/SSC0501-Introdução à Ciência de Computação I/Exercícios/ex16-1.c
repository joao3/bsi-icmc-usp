#include <stdio.h>

int main() {
    FILE *arq;
    char str1[21], str2[21];

    arq = fopen("ex16-1.txt", "w+");
    
    fgets(str1, 20, stdin);
    fprintf(arq, "%s", str1);
    fseek(arq, 0, SEEK_SET);
    fgets(str2, 20, arq);
    fclose(arq);
    printf("%s\n", str2);
}