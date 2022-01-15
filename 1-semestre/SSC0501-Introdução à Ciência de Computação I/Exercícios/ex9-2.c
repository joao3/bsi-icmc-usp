#include <stdio.h>

int main() {
	int mat[5][5], ans[5][5];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	printf("\n\n");

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if ((j == 2 || i == 2) && i != j) {
				ans[i][j] = mat[j][i];
				ans[j][i] = mat[i][j];
			} else {
				ans[i][j] = mat[i][j];
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
}
