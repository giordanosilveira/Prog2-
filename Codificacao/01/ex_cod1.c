#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

int testacharmin (int i, unsigned char *word) {
    if (word[i] >= 224 && word[i] <= 227)
        return 1;
    if (word[i] >= 233 && word[i] <= 234)
        return 2;
    if (word[i] >= 237 && word[i] <= 238)
        return 3;
    if (word[i] >= 243 && word[i] <= 245)
        return 4;
    if (word[i] >= 250 && word[i] <= 251)
        return 5;
    if (word[i] == 231)
        return 6;

    return 0;
}
int testacharmai (int i, unsigned char *word) {

    if (word[i] >= 192 && word[i] <= 195)
        return 1;
    if (word[i] >= 200 && word[i] <= 202)
        return 2;
    if (word[i] >= 205 && word[i] <= 206)
        return 3;
    if (word[i] >= 211 && word[i] <= 213)
        return 4;
    if (word[i] >= 218 && word[i] <= 219)
        return 5;
    if (word[i] == 199)
        return 6;

    return 0;
}
void trocacharmin (int num, int i, unsigned char *word) {

    switch (num) {
        case 1 :
        word[i] = 'a';
        break;

        case 2 :
        word[i] = 'e';
        break;

        case 3 :
        word[i] = 'i';
        break;

        case 4 :
        word[i] = 'o';
        break;

        case 5 :
        word[i] = 'u';
        break;

        case 6 :
        word[i] = 'c';
        break;

        default:
        break;
    }
}
void trocacharmai (int num, int i, unsigned char *word) {

    switch (num) {
        case 1 :
        word[i] = 'A';
        break;

        case 2 :
        word[i] = 'E';
        break;

        case 3 :
        word[i] = 'I';
        break;

        case 4 :
        word[i] = 'O';
        break;

        case 5 :
        word[i] = 'U';
        break;

        case 6 :
        word[i] = 'C';
        break;
    }
}
void turntoascii (unsigned char *word) {

    int i,num;

    i = 0;
    while (word[i] != '\0') {
        num = testacharmin(i,word);
        printf ("%c %d\n", word[i], i);
        if (num) {
            printf ("Oi\n");
            trocacharmin (num,i,word);
        }
        else {
            num = testacharmai (i,word);
            trocacharmai (num,i,word);
        }
        i++;
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