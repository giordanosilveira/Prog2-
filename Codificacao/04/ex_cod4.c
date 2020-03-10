#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void printftabascii () {

    int i;
    for (i = 0; i <= 95; i++) {
        printf ("%d - %c ", i+32, i+32);
        if (i%4 == 0)
            printf ("\n");
    }
    printf ("\n"); 
}
void prnttabasciieISO () { 

    int i;
    char ch;
    for (i = 32; i <= 127; i++) {
        printf ("%d - %c ", i, i);
        if (i%4 == 0)
            printf ("\n");
    }
    printf ("\n");

    for (i = 160; i <= 255; i++) {
        printf ("%d - %c ", i ,i);
        if (i % 4 == 0)
            printf ("\n");
    }
    printf ("\n"); 
}
int main () {

    char *locale;

    setlocale (LC_CTYPE, "pt_BR.ISO-8859-1");

    printf ("Tabela em ascii\n");
    printftabascii ();

    printf ("\n");

    printf ("Tabela ascii + ISO 8895-1");
    prnttabasciieISO ();

    return 0;
}