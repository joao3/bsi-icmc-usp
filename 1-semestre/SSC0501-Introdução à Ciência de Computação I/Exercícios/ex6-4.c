#include <stdio.h>

int main() {
    int n = 1, q = 1;

    while (1) {
        q = n * n;
        if (q > 5000) {
            break;
        }
        printf("%d ", q);
        n += 1;
    }

}