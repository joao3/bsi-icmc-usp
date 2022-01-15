#include <stdio.h>

int main(){
    int num, final;

    printf("Digite um numero: ");
    scanf("%d", &num);

    final = ((num * 3)+1) + ((num * 2 )-1);

    printf("%d", final);
}