#include <stdio.h>

int main(){
    int lado, area, perimetro;

    printf("Digite o tamanho do lado do quadrado: ");
    scanf("%d", &lado);

    area = lado * lado;
    perimetro = lado * 4;

    printf("Area: %d\nPerimetro: %d", area, perimetro);
}