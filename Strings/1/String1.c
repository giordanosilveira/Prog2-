/*
----------------------------------------------------------------ENUNCIADO----------------------------------------------------------------------
|Ler uma string da entrada padrão e escrevê-la na saída padrão ao contrário (do final para o início), de forma similar ao comando rev do Unix.|
-----------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main () {

    int i;
    char string[MAX];

    scanf("%[^\n]", string);
    getchar ();

    for (i=strlen(string); i >= 0; i--)
        printf ("%c", string[i]);

    printf ("\n");
    return 0;
}