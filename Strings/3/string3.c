/*
----------------------------------------------------------------ENUNCIADO----------------------------------------------------------------------
|              Converter as letras de uma string em maiúsculas (dica: estude a estrutura da tabela ASCII antes de implementar).               |
-----------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int main () {

    char string[MAX];
    int i;

    scanf ("%[^\n]", string);
    getchar ();

    for (i = 0; i < strlen(string); i++) {
        if (string[i] > 96 && string[i] < 123)
            string[i] = string[i] - 32;
    }

    printf ("%s\n", string);
    return 0;
}