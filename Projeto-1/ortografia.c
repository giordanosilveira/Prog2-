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

char ** reaDictionary (FILE *arq1, char **words, int *tam) {

    int i;

    *tam = MAX_ALT;
    //fscanf (arq1,"%s",words[i]);
    for (i = 0; ! feof(arq1); i++) {
        fscanf (arq1,"%s",words[i]);
        if (i % (MAX_ALT - 2) == 0) {
            words = (char **)realloc(words,sizeof(char *)*(MAX_ALT+*tam));
            for (int j = i; j < (MAX_ALT + *tam); j++)
                words[j] = (char *)malloc(sizeof(char)*MAX_LARG);
            *tam += MAX_ALT;
        }    

    }
    *tam = i;
    return words;
}

void writedictionary (char ** words, int tam) {

    int i;
    for (i = 0; i < tam; i++) {
        printf ("%s\n", words[i]);
        //printf ("\n");
    }
}

int main () {

    int tam_dict;
    char **ar_dict;
    FILE *dict;

    dict = fopen ("/usr/share/dict/brazilian", "r");

    ar_dict = aloc_array ();                               // Aloca array

    ar_dict = reaDictionary (dict,ar_dict,&tam_dict);

    printf ("%d\n", tam_dict);
    writedictionary (ar_dict,tam_dict);

    return 0;
}