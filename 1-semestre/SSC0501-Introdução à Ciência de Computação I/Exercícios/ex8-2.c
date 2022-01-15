#include <stdio.h>

int main() {
	int ans = 0, arr[10];

	for (int i = 0; i < 10; i++) { 
		scanf("%d", &arr[i]); 
		if (i % 2 != 0) ans += arr[i]; 
	} 
	
	printf("%d", ans);
}
