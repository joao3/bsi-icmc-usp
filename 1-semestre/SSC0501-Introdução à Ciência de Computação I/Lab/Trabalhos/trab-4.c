#include <stdio.h>

int main() {
	int a[5][5], menor, maior;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);

			if ((i == 0 && j == 0) || a[i][j] < menor) menor = a[i][j];
            if ((i == 0 && j == 0) || a[i][j] > maior) maior = a[i][j];
		}
	}

	printf("%d %d", menor, maior);
}
