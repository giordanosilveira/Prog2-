#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void p_char_matrix (char ct, char *tab) {
    *tab = ct;
}
void printmatrix (char **tab, int alt, int larg) {

    int i, j;
    
    for (i = 0; i < alt; i++) {
        for (j = 0; j < larg; j++)
            printf ("%c", tab[i][j]);
        printf ("\n");    
    }

}
void freematrix (char **tab, int alt) {

    int i;

    for (i = 0; i < alt; i++)
        free (tab[i]);
}
int main () {

    char **tabuleiro, ct;
    int larg, alt, i , j; 
    FILE *orig;

    orig = fopen ("mapa.txt", "r");

    if (! orig) {
        perror ("Não foi possível abrir o arquivo");
        exit (1);
    }

    fscanf (orig,"%d %d\n", &alt, &larg);

    tabuleiro = (char **)malloc(sizeof(char *)*alt);
    for (int i = 0; i < alt; i++)
        tabuleiro[i] = (char *)malloc(sizeof(char)*larg);

    i = j = 0;
    ct = fgetc (orig);
    while (ct != EOF) {
        if (j == larg ) {
            i++;
            j = 0;
        }
        else {
            if (ct != '\n') {
                p_char_matrix (ct,&tabuleiro[i][j]);
                j++;
            }
        }
        ct = fgetc (orig);
    }
    printf ("\n");

    printmatrix (tabuleiro,alt,larg);
    printf ("\n");

    freematrix (tabuleiro,alt);
    fclose (orig);

    return 0;
}
