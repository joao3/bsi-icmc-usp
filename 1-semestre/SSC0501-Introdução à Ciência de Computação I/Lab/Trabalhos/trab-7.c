#include <stdio.h>

int func(int n, int *pVet) {
    int count = 0;
    for (int i = 1; i < n; i++) {
        if (count >= 20) break;
        if (n % i == 0) {
            *pVet = i;
            pVet++;
            count++;
        }
    }
    
    return count;
}

int main() {
    int n, vet[20];

    scanf("%d", &n);

    int quant = func(n, &vet[0]);

    for (int i = quant - 1; i >= 0; i--) {
        printf("%d ", vet[i]);
    }
}