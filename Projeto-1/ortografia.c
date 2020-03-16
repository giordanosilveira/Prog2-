#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_ALT 10000
#define MAX_LARG 1024
#define MAX_W 50
#define MINUS 32
#define ZERO 0

unsigned char** aloc_array () {

    unsigned char**matrix;
    
    matrix = (unsigned char**)malloc(sizeof(unsigned char*)*MAX_ALT);
        for (int i = 0; i < MAX_LARG; i++)
            matrix[i] = (char*)malloc(sizeof(char)*MAX_LARG);

    return matrix;
}

unsigned char** reaDictionary (FILE *arq1, unsigned char**words, int *tam) {

    int i;

    *tam = MAX_ALT;
    //fscanf (arq1,"%s",words[i]);
    for (i = 0; ! feof(arq1); i++) {
        fscanf (arq1,"%s",words[i]);
        if (i % (MAX_ALT - 2) == 0) {
            words = (unsigned char**)realloc(words,sizeof(unsigned char*)*(MAX_ALT+*tam));
            for (int j = i; j < (MAX_ALT + *tam); j++)
                words[j] = (unsigned char*)malloc(sizeof(unsigned char)*MAX_LARG);
            *tam += MAX_ALT;
        }    

    }
    *tam = i;
    return words;
}

/*void writedictionary (unsigned char** words, int tam) {

    int i;
    for (i = 0; i < tam; i++) {
        printf ("%s\n", words[i]);
        //printf ("\n");
    }
}*/

int is_char (unsigned char c) {

    if (c >= 65 && c <= 90 || c >= 97 && c <= 122 
        || c >= 192 && c <= 220 || c >= 224 && c <= 252) {
        return 1;
    }
    return 0;

}

void minuscule (unsigned char *word) {

    int i = 0;

    while (word[i] != '\0') {
        if (word[i] >= 65 && word[i] <= 90 || word[i] >= 192 && 220 <= word[i])
            word[i] += MINUS;
        i++;
    }

}

int search_dict (unsigned char * word, unsigned char **dict, int tam) {

    int mid, first, cmp, end;

    first = ZERO;
    end = tam;

    while (first <= tam) {

        mid = (first + end)/2;
        cmp = strcmp(word,dict[mid]);
        if (cmp == ZERO)
            return 1;
        if (cmp < ZERO)
            first = mid;
        else if (cmp > ZERO)
            end = mid + 1;
    }
    return 0;

}

int main () {

    int tam_dict, i;
    unsigned char **ar_dict, c, word[MAX_W];
    FILE *dict, *text;

    dict = fopen ("/usr/share/dict/brazilian", "r");
    //text = fopen ("", "")

    ar_dict = aloc_array ();                               // Aloca array
    ar_dict = reaDictionary (dict,ar_dict,&tam_dict);

    //text = stdin;

    c = fgetc ();
    while (c != EOF) {

        while (! is_char (c) && c != EOF) {
            printf ("%c", c);
            c = getc ();
        }
        
        i = 0;
        word[MAX_W] = {0};
        while (is_char (c) && c != EOF) {
            word[i] = c;
            c = getc ();
        }

        if (c != EOF) {
            minuscule (word);
            if (search_dict (word,ar_dict, tam_dict));
                printf ("%s", word);
            else 
                printf ("[%s]", word);    
        } 
    }

    //writedictionary (ar_dict,tam_dict);

    return 0;
}