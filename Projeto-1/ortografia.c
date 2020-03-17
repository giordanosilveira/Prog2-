#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define H_MAX 10000
#define W_MAX 64
#define ZERO 0
//#define
//#define
//#define
//#define

struct t_dictionary {
    char **memory;
    int s_mem;
    int s_real;
};

typedef struct t_dictionary t_dictionary;

void init_dict (t_dictionary * dict) {
    dict->s_mem = H_MAX;
    dict->s_real = ZERO;
}

char ** allcte_mem () {

    char **matrix;

    matrix = (char **)malloc(sizeof(char *)*H_MAX);
    if (matrix == NULL)
        return NULL;
    for (int i = 0; i < H_MAX; i++) {
        matrix[i] = (char *)malloc(sizeof(char )*W_MAX);
        if (matrix[i] == NULL)
            return NULL;
    }

    return matrix;
}

/*int reallcte_mem (t_dictionary *d) {

    d->memory = realloc(d->memory,(d->s_real + H_MAX)*sizeof(char *));
    if ( ! d->memory )
        return 0;
    
    for (int i = d->s_real; i < (d->s_real + H_MAX); i++) {   
        d->memory[i] = (char *)malloc(sizeof(char)*W_MAX);
        if (d->memory[i] == NULL)
            return 0;
    }
    d->s_mem += H_MAX;
    return 1;


}*/

int is_char (char c){

    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122) 
        || (c >= 192 && c <= 220) || (c >= 224 && c <= 252)) {
        return 1;
    }
    return 0;

}

int l_dictMemory (FILE *arq, t_dictionary *d) {

    int i;

    for (d->s_real = 0; fscanf (arq,"%s",d->memory[d->s_real]) != EOF; d->s_real++ ) {
     
        if (d->s_real % (H_MAX - 2) == 0) {
            d->memory = realloc(d->memory,(d->s_real + H_MAX)*sizeof(char *));
            if ( ! d->memory ) {
                perror ("Couldn't reallocate memory");
                return 0;
            }

            for (int j = d->s_real; j < (d->s_real + H_MAX); j++) {   
                d->memory[j] = (char *)malloc(sizeof(char)*W_MAX);
                if (d->memory[j] == NULL) {
                    perror ("Couldn't reallocate memory");
                    return 0;
                }
            }
            d->s_mem += H_MAX;
        }
    }
    return 1;

}

void w_dictMemory (t_dictionary *d) {

    for (int i = 0; i < d->s_real; i++) {
        printf ("%s", d->memory[i]);
        printf ("\n");
    }
}

void free_memory (t_dictionary *d) {

    for (int i = 0; i < d->s_real; i++)
        free (d->memory[i]);

}
int main () {

    char *locale;
    locale = setlocale (LC_CTYPE, "pt_BR.ISO-8859-1");

    if (! locale) {
        perror ("Não deu boa");
        exit (1);
    }

    t_dictionary dictionary;
    char word[H_MAX], c;
    FILE *dict, *text;

    init_dict (&dictionary);
    dict = fopen ("/usr/share/dict/brazilian", "r");

    if (! dict ) {                                       // check if it was possible to open the file
        perror ("Couldn't open file");
        exit (1);
    }

    dictionary.memory = allcte_mem ();
    if (dictionary.memory == NULL) {
        perror ("Couldn't allocate memory");
        exit (1);
    }

    if ( ! l_dictMemory (dict,&dictionary)) {
        exit (1);
    }

    fclose (dict);

    text = stdin;
    c = fgetc (text); 
    while (c != EOF) {
        printf ("%c", c);
        /*while ((! is_char(c)) && (c != EOF)) {
            printf ("%c", c);
            c = fgetc (text);
        }

        word[H_MAX] = {0};
        int i = 0;
        while ((is_char(c)) && (c != EOF)) {
            minuscule (c);
            word[i] = c;
            i++;
            c = fgetc (text);
        }

        if (srchin_dict (dict,word)) 
            printf ("%s", word[i]);
        else
            printf ("[ %s ]", word[i]);*/ 
        
        c = fgetc (text);
    }

    free_memory (&dictionary);

    return 0;
}