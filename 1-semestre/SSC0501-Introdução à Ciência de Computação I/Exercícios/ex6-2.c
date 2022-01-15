#include <stdio.h>

int main() {
    int soma = 0;
    for (int i = 1, j = 1; j <= 50; j += 1) {
        soma += i/j;
        i += 2;
    }

    printf("%d", soma);
}