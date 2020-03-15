#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_ALT 10000
#define MAX_LARG 1024

char ** aloc_array () {

    char **matrix;
    
    matrix = (char **)malloc(sizeof(char *)*MAX_ALT);
        for (int i = 0; i < MAX_LARG; i++)
            matrix[i] = (char*)malloc(sizeof(char)*MAX_LARG);

    return matrix;
}

void reaDictionary (FILE *arq1, char **words, int *tam) {

    int i;

    i = 0;
    *tam = MAX_ALT;
    while ( feof (arq1) != EOF) {

        fscanf (arq1,"%s",words[i]);
        if (i % (MAX_ALT - 1) == 0) {
            words = (char **)realloc(words,sizeof(char *)*(MAX_ALT+*tam));
            for (int j = i; j < (MAX_ALT + *tam); j++)
                words[j] = (char *)malloc(sizeof(char)*MAX_LARG);

            *tam += MAX_ALT;
        }
        printf ("%d %d\n", i, *tam);
        i++;
    }

}

void writedictionary (char ** words, int tam) {

    int i;
    for (i = 0; i < tam; i++) {
        printf ("%s", words[i]);
        printf ("\n");
    }
}

int main () {

    int tam_dict;
    char **ar_dict;
    FILE *dict;

    setlocale (LC_CTYPE, "pt_br.ISO-8859-1");

    dict = fopen ("brazilian", "r");

    ar_dict = aloc_array ();                               // Aloca array

    reaDictionary (dict,ar_dict,&tam_dict);

    writedictionary (ar_dict,tam_dict);

    return 0;
}