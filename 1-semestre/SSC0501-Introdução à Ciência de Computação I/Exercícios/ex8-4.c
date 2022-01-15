#include <stdio.h>

int main() {
	int a[10], ans = 0, aux = 0;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		if (i > 0) {
			aux = a[i] - a[i-1];
			if (i == 1 || aux > ans) ans = aux;
		}
	}

	printf("%d", ans);
}
