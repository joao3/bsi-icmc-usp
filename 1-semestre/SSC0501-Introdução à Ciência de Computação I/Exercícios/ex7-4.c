#include <stdio.h>

int main() {
    int n, count = 1; scanf("%d", &n);
    float ans = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
        if (count % 2 != 0) {
            ans += 4.0/i; 
            count++;
        } else {
            ans -= 4.0/i;
            count++;
        }
    }

    printf("%f", ans);
}