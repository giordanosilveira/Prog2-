#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void stringcpy (char *word, char *copy) {

    int i;

    i = 0; 
    while (word[i] != '\0') {
        copy[i]=word[i];
        i++;
    }
}
int main () {

    char *word, *copy;
    int tam;

    word = (char *)malloc(sizeof(char)*MAX);
    scanf ("%[^\n]", word);
    getchar ();

    tam = strlen (word);
    if (tam == 0)
        printf ("Não é possivel fazer a cópia");
    else {
        copy = (char*)malloc(sizeof(char)*tam + 1);
        stringcpy (word,copy);
        printf ("%s\n", copy);
    }
    free (word);
    free (copy);
    
    return 0;
}
//banana é uma excelente fonte de potassio
