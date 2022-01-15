#include <stdio.h>

int main() {
    int n1, n2, n3, p = 2, mmc = 1, mdc = 1; scanf("%d %d %d", &n1, &n2, &n3);

    while (1) {
        if (n1 == 1 && n2 == 1 && n3 == 1) break;

        if (n1 % p == 0 && n2 % p == 0 && n3 % p == 0) {
            mmc *= p;
            mdc *= p;
            n1 /= p;
            n2 /= p;
            n3 /= p;
        } else if (n1 % p == 0 && n2 % p == 0) {
            mmc *= p;
            n1 /= p;
            n2 /= p;
        } else if (n2 % p == 0 && n3 % p == 0) {
            mmc *= p;
            n2 /= p;
            n3 /= p;
        } else if (n1 % p == 0 && n3 % p == 0) {
            mmc *= p;
            n1 /= p;
            n3 /= p;
        } else if (n1 % p == 0) {
            mmc *= p;
            n1 /= p;
        } else if (n2 % p == 0) {
            mmc *= p;
            n2 /= p;
        } else if (n3 % p == 0) {
            mmc *= p;
            n3 /= p;
        } else {
            while (1) {
                int count = 0;
                p++;
                for (int i = 1; i <= p; i++) {
                    if (p % i == 0) count++;
                }
                if (count == 2) break;
            }
        }
    }

    printf("%d %d", mmc, mdc);
}