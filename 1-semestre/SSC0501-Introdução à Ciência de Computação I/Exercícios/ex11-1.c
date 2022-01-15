#include <stdio.h>

int main() {
    int m, n; scanf("%d %d", &m, &n);
    int mat[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = (i+1)*(j+1);
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}