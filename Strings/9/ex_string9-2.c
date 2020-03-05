#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void strconcat (char *dest, char *orig, int t1, int t2) {

    int i,j;

    i = 0;

    while (orig[i] != '\0') {
        dest[t1] = orig[i];
        i++;
        t1++;
    }
    dest[t1] = orig[i];
}
int main () {

    char dest[MAX + 1], orig[MAX + 1];
    int tam1, tam2;

    scanf ("%[^\n]", dest);
    getchar();

    scanf ("%[^\n]", orig);
    getchar();

    tam1 = strlen (dest);
    tam2 = strlen (orig);

    if (tam2 == 0)
        printf ("Vai se fuder\n");
    else {
        strconcat (dest,orig,tam1,tam2);
        printf ("%s\n", dest); 
    }

    return 0;
}