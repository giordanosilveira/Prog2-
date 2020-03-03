/*
----------------------------------------------------------------ENUNCIADO----------------------------------------------------------------------
|                                       Calcular o tamanho de uma string (sem usar strlen).                                                   |
-----------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main () {

    int i, cont;
    char string[MAX + 1];

    scanf("%[^\n]", string);
    getchar ();

    i=0;
    cont=0;
    while (string[i] != '\0') {
        cont++;
        i++;
    }

    printf ("%d\n", cont);

    return 0;
}
