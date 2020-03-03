/*
----------------------------------------------------------------ENUNCIADO----------------------------------------------------------------------
|                 Remover de uma string os caracteres que não sejam letras, números ou espaço, sem usar string auxiliar.                       |
-----------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int ehcaracter (char *word, int ind) {
    if (word[ind] < '0' || word[ind] > '9') 
        if (word[ind] < 'a' || word[ind] > 'z') 
            if (word[ind] < 'A' || word[ind] > 'Z') 
                if (word[ind] != ' ')
                    return 0;
    return 1;
}
int main () {

    char string[MAX + 1];
    int i,j; 

    scanf ("%[^\n]", string);
    i = 0;

    while (string[i] != '\0') {
        if (! ehcaracter(string,i)) { 
            j = i;
            while (string[j+1] != '\0') {
                string[j] = string[j+1];
                    j++;
            }
            string[j] = string[j+1];
        }
        else
            i++;
    }
    printf ("%s\n", string);
    return 0;
}