#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S_MAX 256

int main () {

    char line[S_MAX];
    FILE *orig;

    orig = fopen ("texto.txt", "r");

    if (! orig) {
        perror ("Não foi possível abrir o arquivo");
        exit (1);
    }

    while ( ! (fscanf(orig,"%[^\n]",line))) {
        //testa lin
    }
    return 1;
}