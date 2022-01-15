#include <stdio.h>
int mdc(int n1, int n2, int n3) {
    int aux;
    while (1) {
        int temp = n2;
        n2 = n3 % n2;
        n3 = temp;
        if (n3 % n2 == 0) {
            aux = n2;
            break; 
        }
    }
    while (1) {
        int temp = n1;
        n1 = aux % n1;
        aux = temp; 
        if (aux % n1 == 0) {
            return n1;
        }
    }
}

int mmc(int n1, int n2, int n3) {
    int aux = (n1 * n2) / mdc(n1, n1, n2);
    return (aux * n3) / mdc(aux, aux, n3);
}

int main() {
    int n1, n2, n3, aux;
    scanf("%d %d %d", &n1, &n2, &n3);
    if (n1 < n3) {
        aux = n1;
        n1 = n3;
        n3 = aux;
    }
    printf("%d %d", mmc(n1, n2, n3), mdc(n1, n2, n3));
}