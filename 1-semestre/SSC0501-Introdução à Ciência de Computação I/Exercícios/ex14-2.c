#include <stdio.h>
#include <string.h>

void func(char str[], char ch) {
    char *posi = strchr(str, ch);
    while (posi != NULL) {
        while (*posi != '\0') {
            *posi = *(posi + 1);
            posi++;
        }

        posi = strchr(str, ch);
    }
}

int main() {
    char str[10], ch;
    fgets(str, 10, stdin);
    scanf("%c", &ch);

    func(str, ch);

    for (int i = 0; i < 10; i++) {
        printf("%c", str[i]);
    }
}