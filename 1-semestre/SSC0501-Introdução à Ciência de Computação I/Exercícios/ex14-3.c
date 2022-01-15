#include <stdio.h>
#include <string.h>

int func(char a[], char b[]) {
    for (int i = 0; i < 10; i++) {
        if (b[0] == a[i]) {
            for (int j = 0; j < 5; j++) {
                if (i + j > 10) break;
                if (b[j] != a[i+j]) break;
                if (b[j+1] == '\0') return 1;
            }
        }
    }

    return 0;
}

int main() {
    char a[10], b[5];
    scanf("%s %s", a, b);

    printf("%d", func(a, b));
}