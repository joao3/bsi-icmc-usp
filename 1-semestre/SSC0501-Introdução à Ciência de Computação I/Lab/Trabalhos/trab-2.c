#include <stdio.h>

int main() {
    float e, r;
    int n;
    scanf("%f %d", &e, &n);

    r = e / 2;
    if (n == 1) printf("%f", r);
    else {
        for (int i = 0; i < n - 1; i++) {
            r = (r + (e/r))/2;

            if (i == n - 2) printf("%f", r);
        }
    }
}