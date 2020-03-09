#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#define MAX 100

//wchar_t utf8strl ();
int main () {

    char *locale;
    wchar_t word[MAX], letra;

    locale = setlocale (LC_CTYPE, "") ;
    if (!locale)
    {
        fprintf(stderr, "Can't set the specified locale! " "Check LANG, LC_CTYPE, LC_ALL.\n");
        return (1);
    }

    fgetws(word,MAX,stdin);
    
    printf ("Entre com o número da sequência\n");

    //letra = utf8strl ();
    wprintf (L"%ls\n", word);

    return 0;   
}