#include <stdio.h>
#include <stdlib.h>

void mult(int n, int vet[]) {
    for (int i = 0; i < n; i++) {
        vet[i] = n * (i + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *vet = (int *) malloc(n * sizeof(int));
    if (vet == NULL) exit(1);

    mult(n, vet);

    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }

    free(vet);
}