#include <stdio.h>

int main() {
    int n, a1 = 0, a2 = 1, ans = 0, count = 0;

    scanf("%d", &n);
    printf("0");
    for (int i = 1; 1 == 1; i++) {
        ans = a1 + a2;
        if (ans > n && count == 0){
            count++;
        } else if(ans > n) break;
        printf(" %d", ans);
        if (i % 2 == 0) a1 = ans; else a2 = ans;
    }
}