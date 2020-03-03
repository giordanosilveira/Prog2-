/*
----------------------------------------------------------------ENUNCIADO----------------------------------------------------------------------
|                 Remover de uma string os caracteres que não sejam letras, números ou espaço, sem usar string auxiliar.                       |
-----------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int ehcaracter (char *word, int ind) { // Basicamente testa se é um caracter válido
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

    scanf ("%[^\n]", string); // Lê uma string enquando não enxerga o ENTER
    i = 0;

    while (string[i] != '\0') { // Vai até o final da string 
        if (! ehcaracter(string,i)) { 
            j = i;
            while (string[j+1] != '\0') { //Sê não o char n for válido, pega o restante da palavra e puxa-a
                string[j] = string[j+1];
                    j++;
            }
            string[j] = string[j+1]; // Troca final por causa do \0
        }
        else // Se o caracter for válido é que att, senão da pau
            i++;
    }
    printf ("%s\n", string);
    return 0;
}
