#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    FILE *arq;
    float pf,soma;
    int cont;

    arq = fopen ("numeros.txt", "r");
    
    if (! arq) {
        perror ("Arquivo não deu bom");
        exit (1);
    }

    soma = 0;
    cont = 0;
    while (! feof(arq)) {
        fscanf (arq,"%f",&pf);
        soma = soma + pf;
        cont++;
    }

    fclose (arq);

    soma = soma/cont;
    printf ("Média -> %f\n", soma);

    return 0;
}