#include <stdio.h>

int main(){
    float mp, p1, p2, p3, mt, t1, t2, mf;

    printf("Digite sua nota na prova 1: ");
    scanf("%f", &p1);
    printf("Digite sua nota na prova 2: ");
    scanf("%f", &p2);
    printf("Digite sua nota na prova 3: ");
    scanf("%f", &p3);
    printf("Digite sua nota no trabalho 1: ");
    scanf("%f", &t1);
    printf("Digite sua nota no trabalho 2: ");
    scanf("%f", &t2);

    mp = (2 * p1 + 3 * p2 + 3 * p3)/8;
    mt = (t1 + t2)/2;
    mf = (7 * mp + 3 * mt)/10;

    printf("Media nas provas: %f\nMedia nos trabalhos: %f\nMedia final: %f", mp, mt, mf);
}