#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int ehcharinvalido (int i, char *word) {

    if (word[i] < 'a' || word[i] > 'z')
        if (word[i] < 'A' || word[i] > 'Z')
            if (word[i] < 0 || word[i] > 9)
                if (word[i] != ' ')
                    return 1;
    return 0;

}

void deslocastring (int i, int *tam, char *word) {

    int j;

    j = *tam;
    while (j > i) {
        word[j + 3] = word[j];
        j--;
    }
    tam += 3;
}
void putconchete (int i, char *word) {

    word[i] = '[';
    word[i+2] = ']';

}
void deslocacharinvalido (int i, char *word) {

    word[i + 1] = word[i];
    
}
int main () {

    char word[MAX];
    int i, tam;

    scanf ("%[^\n]", word);
    getchar ();

    tam = strlen (word);
    i = 0;

    while (i < tam) {
        if (ehcharinvalido(i,word)) {
            printf ("%c - %d\n", word[i], i);
            deslocastring (i,&tam,word);
            deslocacharinvalido (i,word);
            putconchete (i,word);
            i += 3;
        }
        i++;
    }
    printf ("%s\n", word);
    return 0;
}