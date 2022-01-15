#include <stdio.h>
#include <string.h>

int numLet(char nome[]) {
    int count = 0;
    for (int i = 0; i < 200; i++) {
        if (nome[i] == '\0') break;
        if ((nome[i] == ' ' && nome[i-1] != ' ' && nome[i-1] != '\n' && nome[i-1] != '\0') || (i == 0 && nome[i] != ' ' && nome[i] != '\0' && nome[i] != '\n')) 
            count++;
    }

    return count;
}

int main() {
    char nome[200];
    fgets(nome, 199, stdin);

    printf("%d\n", numLet(nome));
}