#include <stdio.h>

int main() {
    float p1, p2, p3, t1, t2, m1, m2, ans;
    scanf("%f %f %f %f %f", &p1, &p2, &p3, &t1, &t2);

    if (p1 >= p3 && p2 >= p3) {
        m1 = p1; m2 = p2;
    } else if (p1 >= p2 && p3 >= p2) {
        m1 = p1; m2 = p3;
    } else {
        m1 = p2; m2 = p3;
    }
    ans = (7 * ((m1 + m2) / 2) + 3 * ((t1 + t2) / 2))/10;
    printf("%f", ans);
}