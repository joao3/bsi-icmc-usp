#include <stdio.h>

int main() {
    int n1, n2, n3, menor, maior, outro;

    printf("Digite 3 numeros: ");
    scanf("%d %d %d", &n1, &n2, &n3);

    if (n1 < n2 && n1 < n3) {
        menor = n1;
    }
    else if (n2 < n1 && n2 < n3) {
        menor = n2;
    }
    else {
        menor = n3;
    }

    if (n1 > n2 && n1 > n3) {
        maior = n1;
    }
    else if (n2 > n1 && n2 > n3) {
        maior = n2;
    }
    else {
        maior = n3;
    }

    if (n1 != menor && n1 != maior) {
        outro = n1;
    }
    else if (n2 != menor && n2 != maior) {
        outro = n2;
    }
    else {
        outro = n3;
    }

    printf("Ordem: %d - %d - %d", menor, outro, maior);

}