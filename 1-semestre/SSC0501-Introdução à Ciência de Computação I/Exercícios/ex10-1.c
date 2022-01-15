#include <stdio.h>

int area(int base, int altura) {
    return base * altura;
}

int main() {
    int base, altura;

    scanf("%d %d", &base, &altura);
    printf("%d\n", area(base, altura));
}