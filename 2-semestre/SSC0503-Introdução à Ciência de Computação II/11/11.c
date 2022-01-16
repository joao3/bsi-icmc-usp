#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STRING 400

typedef struct reads_st
{
    char **strings;
    int n;
} READS;

void solve(READS *reads);
int overlap(char *s1, char *s2);
READS * alolcar_reads(int n);
char * montar_reads(char *s1, char *s2);
void desalocar_reads(READS *reads);
char ** alocar_matriz_string(int n);
void desalocar_matriz_string(char **strings, int n);
int max(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);
    READS *reads = alolcar_reads(n);
    for (int i = 0; i < reads->n; i++)
    {
        scanf("%s", reads->strings[i]);
    }
    solve(reads);
}

void solve(READS *reads)
{
    if (reads->n <= 1)
    {
        printf("%s\n", reads->strings[0]);
        desalocar_reads(reads);
        return;
    }

    int maior_overlap = 0;
    int pos_maior_overlap_a = 0;
    int pos_maior_overlap_b = 1;
    for (int j = 0; j < reads->n; j++)
    {
        for (int k = 0; k < reads->n; k++)
        {
            if (j != k)
            {
                int overlap_temp = overlap(reads->strings[j], reads->strings[k]);
                if (overlap_temp > maior_overlap)
                {
                    maior_overlap = overlap_temp;
                    pos_maior_overlap_a = j;
                    pos_maior_overlap_b = k;
                }
            }
        }
    }
    READS *reads_novos = alolcar_reads(reads->n - 1);
    char *read_montada = montar_reads(reads->strings[pos_maior_overlap_a], reads->strings[pos_maior_overlap_b]);
    strcpy(reads_novos->strings[0], read_montada);
    free(read_montada);
    int j = 1;
    for (int i = 0; i < reads->n; i++)
    {
        if (i != pos_maior_overlap_a && i != pos_maior_overlap_b)
        {
            strcpy(reads_novos->strings[j], reads->strings[i]);
            j++;
        }
    }
    desalocar_reads(reads);
    solve(reads_novos);
}

char * montar_reads(char *s1, char *s2)
{
    char *sm = (char *) calloc(TAM_STRING, sizeof(char));
    if (strlen(s1) < strlen(s2) && strstr(s2, s1) && overlap(s1, s2) == strlen(s1))
    {
        strcpy(sm, s2);
        return sm;
    }
    char *s2m = s2 + overlap(s1, s2);
    strcpy(sm, s1);
    strcat(sm, s2m);
    return sm;
}

int overlap(char *s1, char *s2)
{
    int overlap = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int v = 0;
    for (int i = len1 - 1; v < len2 - 1 && v < len1; i--, v++)
    {
        if (s1[i] == s2[0])
        {
            int j = 1;
            while (s1[i + j])
            {
                if (s1[i + j] != s2[j])
                {
                    break;
                }
                j++;
            }
            if (!s1[i + j])
            {
                overlap = max(overlap, j);
            }
        }
    }
    if (len1 < len2 && strstr(s2, s1))
    {
        return len1;
    }
    return overlap;
}




int max(int a, int b)
{
    return (a > b) ? a : b;
}

READS * alolcar_reads(int n)
{
    READS *reads = (READS *) malloc(1 * sizeof(READS));
    reads->n = n;
    reads->strings = alocar_matriz_string(n);
    return reads;
}

void desalocar_reads(READS *reads)
{
    desalocar_matriz_string(reads->strings, reads->n);
    free(reads);
}

char ** alocar_matriz_string(int n)
{
    char **strings = (char **) calloc(n, sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        strings[i] = (char *) calloc(TAM_STRING, sizeof(char));
    }
    return strings;
}

void desalocar_matriz_string(char **strings, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(strings[i]);
    }
    free(strings);
}