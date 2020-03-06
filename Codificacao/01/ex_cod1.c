#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int testacharmin (int i, unsigned char *word) {
    if (word[i] < 224 || word[i] > 227)
        return 1;
    if (word[i] < 233 || word[i] > 234)
        return 2;
    if (word[i] < 237 || word[i] > 238)
        return 3;
    if (word[i] < 243 || word[i] > 245)
        return 4;
    if (word[i] < 250 || word[i] > 251)
        return 5;
    if (word[i] == 231)
        return 6;

    return 0;
}
int testacharmai (int i, unsigned char *word) {

    if (word[i] < 192 || word[i] > 195)
        return 1;
    if (word[i] < 200 || word[i] > 202)
        return 2;
    if (word[i] < 205 || word[i] > 206)
        return 3;
    if (word[i] < 211 || word[i] > 213)
        return 4;
    if (word[i] < 218 || word[i] > 219)
        return 5;
    if (word[i] == 199)
        return 6;

    return 0;
}
void turntoascii (unsigned char *word) {

    int i, tam;

    tam = strlen (word);
    i = 0;
    while (i < tam) {
        if (testachar(i,word))
            trocachar (i,word)
    }
}
int main () {

    unsigned char word[MAX];

    scanf ("%[^\n]", word);
    getchar ();

    turntoascii (word);

    printf ("%s\n", word);
    return 0;
}