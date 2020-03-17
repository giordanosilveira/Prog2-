#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv) {

    FILE *orig, *dest;
    char c;

    orig = fopen (argv[1], "r");
    //t = fopen (argv[2], "w");

    if (! orig ) {
        perror ("Não foi possível abrir o arquivo");
        exit (1);
    }

    /*if( access( argv[2], F_OK ) != -1 ) {
        printf ("O arquivo já existe\n");
        exit (1);
    }*/

    c = fgetc (orig); 
    while (c != EOF) {
        printf ("%c",c);
        c = fgetc (orig);
    }
    //fprintf (dest,"%c", '\n');

    return 0;
}