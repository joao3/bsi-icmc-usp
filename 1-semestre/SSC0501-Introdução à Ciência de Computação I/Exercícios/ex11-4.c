#include <stdio.h>

int main() {
    int l, a;
    scanf("%d %d", &l, &a);

    for (int i = 1; i <= a; i++) {
        if (i == 1 || i == a) {
            printf("+");
            for (int j = 1; j <= l - 2; j++) printf("-");
            printf("+");
        } else {
            printf("|");
            for (int j = 1; j <= l - 2; j++) printf(" ");
            printf("|");
        }
        printf("\n");
    }
}