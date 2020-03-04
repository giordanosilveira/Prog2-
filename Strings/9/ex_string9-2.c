#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void stringcat (char *word1, char *word2, char *cat) {

    int i,j;

    i = 0;
    while (word1[i] != '\0') {
       cat[i] = word1[i];
       i++;
    }

    j = 0;
    while (word2[j] != '\0') {
        cat[i-1] = word2[j];
        i++;
    }
}

int main () {

    char *word1, *word2, *cat;
    int tam1, tam2;

    word1 = (char*)malloc(sizeof(char)*MAX);
    word2 = (char*)malloc(sizeof(char)*MAX);
    scanf ("%[^\n]", word1);
    getchar ();
    scanf ("%[^\n]", word2);
    getchar ();

    tam1 = strlen (word1);
    tam2 = strlen (word2);

    if (tam1 == 0 && tam2 == 0)
        printf ("Não é possivel concatenar");
    else {
        cat = (char *)malloc(sizeof(char)*(tam1 + tam2));
        stringcat (word1,word2,cat);
        printf ("%s\n", cat);
    }

    return 0;
}