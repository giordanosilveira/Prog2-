#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    FILE *arq;
    int cont;

    arq = fopen ("texto.txt", "r");
    if ( ! arq ) {
        perror ("Não deu para abrir");
        exit (1);
    }

    cont = 0;
    while (fgetc(arq) != EOF)
        cont++;
    
    printf ("Tamanho = %d\n", cont);

    fclose (arq);
    return 0;
}