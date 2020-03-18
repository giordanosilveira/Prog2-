#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define H_MAX 10000
#define W_MAX 64
#define ZERO 0
#define MINUS 32
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

int is_char (int c){

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
void minuscule (int c) {

    if ((c >= 65 && c <= 90) || (c >= 192 && 220 <= c))
        c += MINUS;
    
}

int s_cmp (char *dict, char *word) {

    

}
int srchin_dict (char *word, t_dictionary *dict) {

    int first, end, mid, cmp = 1;

    first = 0;
    end = dict->s_real - 1;
    while (first < end) {
        
        mid = (first + end)/2;
        cmp = cmp * -1; 

        printf ("%s -> %s\n", dict->memory[mid], word);
        //s_cmp (dict->memory[mid],word);
        
        if (cmp == 0)
            return 1;
        else if ( cmp < 0 )
            end = mid - 1;
        else
            first = mid;
    }
    return 0;

}

int main () {

    char *locale;
    locale = setlocale (LC_CTYPE, "pt_BR.ISO-8859-1");

    if (! locale) {
        perror ("Can't set the specified locale");
        exit (1);
    }

    t_dictionary dictionary;
    char word[W_MAX], c;
    FILE *dict, *text;

    init_dict (&dictionary);
    dict = fopen ("brazilian.txt", "r");

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

    int i;
    text = stdin;
    i = fgetc (text); 
    while (i != EOF) {
        
        while ((! is_char(i)) && (i != EOF)) {
            c = (char)i;
            printf ("%c", c);
            i = fgetc (text);
        }

        word[0] = '\0'; 
        int j = 0;
        while ((is_char(i)) && (i != EOF)) {
            minuscule (i);
            c = (int)i;
            word[j] = c;
            j++;
            i = fgetc (text);
        }
        word[j] = '\0';

        if (srchin_dict (word,&dictionary)) 
            printf ("%s", word);
        else
            printf ("[ %s ]", word); 
        
        //i = fgetc (text);
    }

    printf("\n");
    free_memory (&dictionary);

    return 0;
}
