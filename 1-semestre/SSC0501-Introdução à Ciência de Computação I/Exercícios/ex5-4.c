#include <stdio.h>

int main() {
    int inicial, final;

    scanf("%d %d", &inicial, &final);

    for (int i = inicial; i <= final; i++) {
        if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0)) {
            printf("%d ", i);
        }
    }
}
