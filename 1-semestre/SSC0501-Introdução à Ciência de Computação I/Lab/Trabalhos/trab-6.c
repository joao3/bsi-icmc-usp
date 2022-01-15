#include <stdio.h>

int * func(int vet[10]) {
    for (int i = 0; i < 10; i++) {
        if (vet[i] < 0) vet[i] *= -1;
    }

    return &vet[0];
}

int main() {
    int vet[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);
    }

    int *end = func(&vet[0]);

    for (int i = 0; i < 10; i++) {
        printf("%d ", end[i]);
    }
}