#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S_MAX 1024

int main () {

    char line[S_MAX],word[S_MAX], *here;
    FILE *orig;

    orig = fopen ("texto.txt", "r");

    if (! orig) {
        perror ("Não foi possível abrir o arquivo");
        exit (1);
    }

    scanf ("%s", word);
    while ( fgets (line,S_MAX,orig)) {
        here = strstr (line,word);
        //printf ("%s\n",word);
        if (here) {
            printf ("Existe\n");
            return 0;
        }
    }
    printf ("Não existe\n");
    return 0;
}