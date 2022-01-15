#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int mat[5][5], aux[25], count = 0;

    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            while (1) {
                int verify = 0;
                int num = rand();
                num = num % 100;
                if (num == 100) num--;

                if (i == 0 && j == 0) {
                    mat[i][j] = num;
                    aux[0] = num;
                    count++;
                    break;
                }

                for (int k = 0; k < count; k++) {
                    if (num == aux[k]) verify++;
                }
                if (verify == 0) {
                    mat[i][j] = num;
                    aux[count] = num;
                    count++;
                    break;
                }

            }
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

}