/*
----------------------------------------------------------------ENUNCIADO----------------------------------------------------------------------
|                   Remover de uma string caracteres repetidos em sequência (rr, ss, ee, etc), sem usar string auxiliar.                      |
-----------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int ehcaracter (char *word, int ind) {
    if (word[ind] == word[ind + 1]) 
        return 0;
    return 1;
}
int main () {

    char string[MAX + 1], lixo;
    int i,j; 

    scanf ("%[^\n]", string);
    i = 0;

    while (string[i] != '\0') {
        if (! ehcaracter(string,i)) { 
            j = i;
            lixo = string[j+1];
            while (string[j] == lixo) {
                while (string[j+1] != '\0') {
                    string[j] = string[j+1];
                        j++;
                }
                string[j] = string[j+1];
            }
        }
        else {
            if (lixo == string[i]) {
                j = i;
                while (string[j+1] != '\0') {
                    string[j] = string[j+1];
                        j++;
                }
                string[j] = string[j+1];
            }
            i++;
        }
    }
    printf ("%s\n", string);
    return 0;
}