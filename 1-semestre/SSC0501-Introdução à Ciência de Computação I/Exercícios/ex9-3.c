#include <stdio.h>

int main() {
	int mat[5][5], a, b, ans = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	scanf("%d %d", &a, &b);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (mat[i][j] >= a && mat[i][j] <= b) ans++;
		}
	}
	
		printf("%d", ans);
}
