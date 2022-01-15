#include <stdio.h>

int main() {
    int vet[20], ans[20], count = 1, temp = 1;
    for (int i = 0; i < 20; i++) {
        scanf("%d", &vet[i]);
    } 
    ans[0] = vet[0];
    for (int i = 1; i < 20; i++) {
        int aux = 0;
        count = temp;
        for (int j = 0; j < count; j++) {
            if (vet[i] == ans[j]) {
                aux++;
            }
            if (j == count - 1 && aux == 0) {
                ans[count] = vet[i];
                temp++;
            }
        }
    }
    for (int i = 0; i < temp; i++) {
        printf("%d ", ans[i]);
    }
}