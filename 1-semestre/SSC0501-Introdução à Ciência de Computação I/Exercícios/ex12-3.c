#include <stdio.h>

void func(int vet[], int *pb, int *pc, int *contPar, int *contImp) {
    for (int i = 0; i < 20; i++) {
        if (vet[i] % 2 == 0) {
            pb[i] = vet[i];
            (*contPar)++;
        } else {
            pc[i] = vet[i];
            (*contImp)++;
        }
    }
}

int main() {
    int a[20], b[20], c[20], contPar = 0, contImp =0;

    for (int i = 0; i < 20; i++) {
        scanf("%d", &a[i]);
    }

    func(a, b, c, &contPar, &contImp);

    printf("\nPares: ");
    for (int i = 0; i < contPar; i++) {
        printf("%d ", b[i]);
    }
    printf("\nQuantidade de pares: %d\n", contPar);

    printf("Impares: ");
    for (int i = 0; i < contImp; i++) {
        printf("%d ", c[i]);
    }
    printf("\nQuantidade de impares: %d\n", contImp);

}