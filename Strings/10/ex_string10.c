#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int ehpalindromo (char *word) {

    int i, j;

    j = strlen(word) - 1;
    i = 0;

    while (j > i) {
        printf ("%c %c\n", word[i], word[j]);
        if (word[i] == ' ')
            i++;
        if (word[j] == ' ')
            j--;
        if (word[i] != word[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}
int main () {

    char word[MAX];

    scanf ("%[^\n]", word);
    getchar();

    if (ehpalindromo(word))
        printf ("É palindromo\n");
    else
        printf ("Não é palíndromo\n");

    return 0;
}
