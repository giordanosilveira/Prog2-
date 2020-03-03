/*
----------------------------------------------------------------ENUNCIADO----------------------------------------------------------------------
|                   Remover de uma string caracteres repetidos em sequência (rr, ss, ee, etc), sem usar string auxiliar.                      |
-----------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int ehcaracter (char *word, int ind) { // Basicamente chega se o char a frente é igual, se sim, retorna 0
    if (word[ind] == word[ind + 1]) 
        return 0;
    return 1;
}
int main () {

    char string[MAX + 1], lixo;
    int i,j; 

    scanf ("%[^\n]", string); // Enquanto não enxerga um ENTER, continua lendo
    i = 0;

    while (string[i] != '\0') { // Vai até o final da string
        if (! ehcaracter(string,i)) { 
            j = i;
            lixo = string[j+1]; // Ajuda na última comparação
            while (string[j] == lixo) { // Enquanto for igual ao lixo, vai puxando a palavra 
                while (string[j+1] != '\0') { // Puxa a palavra para trás 
                    string[j] = string[j+1];
                        j++;
                }
                string[j] = string[j+1]; // Troca por causa do \0 
            }
        }
        else {
            if (lixo == string[i]) { // Para cobrir o caso ímpar
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
