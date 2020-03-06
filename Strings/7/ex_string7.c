#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int ehcharinvalido (int i, char *word) {

    if (word[i] < 'a' || word[i] > 'z')
        if (word[i] < 'A' || word[i] > 'Z')
            if (word[i] < 48 || word[i] > 57)
                if (word[i] != ' ')
                    if (word[i] != '\0')
                    return 1;
    return 0;

}

void deslocastring (int i, char *word) {

    int j, tam;

    tam = strlen(word);
    while (tam >= i) {
        word[tam + 1] = word[tam];
        tam--;
    }

}
void putconchete (int i, char *word) {

    word[i + 1] = '[';
    word[i + 3] = ']';

}
void deslocacharinvalido (int i, char *word) {

    word[i + 1] = word[i];
    
}
int main () {

    char word[MAX];
    int i, tam;

    scanf ("%[^\n]", word);
    getchar ();

    i = 0;
    while (word[i] != '\0') {
        if (ehcharinvalido(i+1,word)) {
            deslocastring(i+1,word);
            deslocastring(i+3,word);
            putconchete(i,word);
            i += 3;
        }
        i++;
    }
    printf ("%s\n", word);
    return 0;
}