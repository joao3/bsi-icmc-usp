#include <stdio.h>
#include <stdlib.h>

void soma_vetor(int *vetor1, int *vetor2, int **vetor_res, int n) {
    *vetor_res = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*vetor_res)[i] = vetor1[i] + vetor2[i];
    }
}

int main() {
    int vet1[5] = {0, 1, 2, 3, 4}, vet2[5] = {10, 9, 8, 5, 1}, n = 5, *vet_res;

    soma_vetor(vet1, vet2, &vet_res, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", (vet_res)[i]);
    }
}