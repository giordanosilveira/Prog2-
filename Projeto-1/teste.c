#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    FILE *input;
    char palavra[50], c;
    int i;

    input = stdin;
    c = fgetc (input);
    i = 0;
    while (c != EOF) {
        if (c != ' ' && c != '\n')
            palavra[i] = c;
        printf ("%c\n", c);
        c = fgetc (input);
        i++;
    }
    
    printf ("%c\n", palavra[0]);
    printf ("%c\n", palavra[1]);
    printf ("%c\n", palavra[2]);
    printf ("%c\n", palavra[3]);
    printf ("%c\n", palavra[4]);
    printf ("%c\n", palavra[5]); 
    printf ("%c\n", palavra[6]);
    printf ("%c\n", palavra[7]);
    printf ("%s\n", palavra);

    return 0;
}