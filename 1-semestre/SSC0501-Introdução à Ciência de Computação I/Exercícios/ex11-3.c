#include <stdio.h>

int main() {
    int vet[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 10; j++) {
            if (vet[i] > vet[j]) {
                int aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", vet[i]);
    }
}