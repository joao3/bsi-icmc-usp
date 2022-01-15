#include <stdio.h>

int main() {
	int mat[4][5], ans[5] = {0, 0, 0, 0, 0};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			ans[i] += mat[j][i];
		}
		printf("%d ", ans[i]);
	}
}
