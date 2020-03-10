#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

unsigned char aumentachar (unsigned char ant) {

    if ((ant >= 97 && ant <= 122) || (ant >= 224 && ant <= 252))
        ant = ant - 32;

    return ant;
}
int main () {

    FILE *orig, *dest;
    unsigned char ant, dps;
 
    setlocale (LC_CTYPE, "pt_BR.ISO-8859-1");
    
    orig = fopen ("minus.txt", "r");
    dest = fopen ("maiusc.txt", "w");

    if ( ! orig ) {
        perror ("Não deu para abrir o arquivo");
        exit (1);
    }

    ant = fgetc(orig);
    while ( ! feof(orig) ) {
        dps = aumentachar (ant);
        fprintf (dest,"%c",dps);
        ant = fgetc(orig);
    }

    fclose (dest);
    fclose (orig);
    return 0;
}