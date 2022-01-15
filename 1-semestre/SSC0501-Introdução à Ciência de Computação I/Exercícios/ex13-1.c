#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float *vet, sum = 0;

    scanf("%d", &n);

    vet = (float *) malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        scanf("%f", &vet[i]);
        sum += vet[i];
    }

    free(vet);

    printf("%.2f", sum/n);
}