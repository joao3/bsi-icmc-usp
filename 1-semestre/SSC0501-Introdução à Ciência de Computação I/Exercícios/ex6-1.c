#include <stdio.h>

int main() {
    int x, y, resultado = 1;

    scanf("%d %d", &x, &y);

    for (int i = 0; i < y; i += 1) {
        resultado *= x;
    }

    printf("%d", resultado);
}