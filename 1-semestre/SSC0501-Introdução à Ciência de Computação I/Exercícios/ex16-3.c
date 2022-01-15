#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *a, *b;
    char na[21], nb[21], temp[101];

    scanf("%s %s", na, nb);

    a = fopen(na, "r+");
    b = fopen(nb, "w+");
    if (a == NULL || b == NULL) exit(0);

    while(!feof(a)) {
        fgets(temp, 100, a);
        fprintf(b, "%s", temp);
    }

    fclose(a);
    fclose(b);
}