#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#define MAX 100

wchar_t utf8strl (int num, wchar_t *word) {
    return word[num];
}

int main () {

    char *locale;
    wchar_t word[MAX], letra;
    int seq;

    locale = setlocale (LC_CTYPE, "") ;
    if (!locale)
    {
        fprintf(stderr, "Can't set the specified locale! " "Check LANG, LC_CTYPE, LC_ALL.\n");
        return (1);
    }

    scanf ("%d", &seq);

    fgetws(word,MAX,stdin);
    
    //printf ("Entre com o número da sequência\n");


    letra = utf8strl (seq,word);

    printf ("[%lc] ", letra);
    wprintf (L"%ls\n", word);

    return 0;   
}