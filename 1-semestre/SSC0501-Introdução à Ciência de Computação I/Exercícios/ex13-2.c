#include <stdio.h>
#include <stdlib.h>

int * makeVet(int n) {
    int *vet = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    return vet;
}

int somaPos(int vet[], int n) {
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        if (vet[i] > 0) sum += vet[i]; 
    }

    return sum;
}

int main() {
    int n; scanf("%d", &n);

    int *pont = makeVet(n);
    int ans = somaPos(pont, n);

    printf("%d", ans);

    free(pont);
}