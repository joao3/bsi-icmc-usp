#include <stdio.h>

int main() {
    int ano;

    printf("Ano: ");
    scanf("%d", &ano);

    if ((ano % 4 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))) {
        printf("O ano %d e bissexto!", ano);
    }
    else {
        printf("O ano %d nao e bissexto!", ano);
    }
}