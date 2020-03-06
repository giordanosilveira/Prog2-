#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int testacharmai (int i, unsigned char *word) {

    if (word[i] < 192 || word[i] > 195)
        return 1;
    if (word[i] < 200 || word[i] > 202)
        return 2;
    if (word[i] < 205 || word[i] > 206)
        return 3;
    if (word[i] < 211 || word[i] > 212)
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

        switch (testachar(i,word))
        {
        case /* constant-expression */:
            /* code */
        break;
    
        case /* constant-expression */:
            /* code */
        break;
    
        case /* constant-expression */:
            /* code */
        break;
    
        case /* constant-expression */:
            /* code */
        break;
    
        case /* constant-expression */:
        /* code */
        break;
    
        case /* constant-expression */:
            /* code */
        break;
    
        default:
        break;
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