#include <stdio.h>

int main() {
    int x, y, soma = 0;

    scanf("%d %d", &x, &y);

    for (int i = x; i <= y; i += 1) {
        soma += i;
    }

    printf("%d", soma);
}