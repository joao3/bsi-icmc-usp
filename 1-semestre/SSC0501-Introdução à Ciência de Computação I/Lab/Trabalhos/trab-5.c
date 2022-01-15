#include <stdio.h>

int primo(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {   
            count++;
        }
    }
    if (count == 2) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (primo(i) == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}