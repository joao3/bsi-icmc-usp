#include <stdio.h>

void func(float n, float *pFrac, int *pIn) {
    *pIn = (int)n;
    *pFrac = n - *pIn;
}

int main() {
    float n, frac;
    int in;

    scanf("%f", &n);

    func(n, &frac, &in);

    printf("%d %f", in, frac);
}