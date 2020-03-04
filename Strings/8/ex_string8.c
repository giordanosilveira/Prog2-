/*
----------------------------------------------------------------ENUNCIADO----------------------------------------------------------------------
|                                           Escreva uma função int busca(agulha, palheiro),                                                    |
|                   que busca a string agulha dentro da string palheiro, sem usar funções prontas da biblioteca C.                             | 
|            A função deve retornar o índice onde agulha começa em palheiro, -1 se não for encontrada ou -2 em caso de erro                    | 
|                                                 (uma ou ambas as strings são nulas).                                                         |
-----------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int busca (char *search, char *palavra) {

    int tam, tamsrch, i, j, k;

    tam = strlen (palavra);
    tamsrch = strlen (search);

    if ((tam == 0 || tamsrch == 0) || tamsrch > tam)
        return -2;

    i = 0;
    while (i < tam) {
        j = 0;
        k = i;
        while (search[j] == palavra[k]) {

            if (j == tamsrch - 1)
                return i;
            j++;
            k++;
        }
        i++;
    }
    return -1;

}
int main () {

    char palavra[MAX], search[MAX];
    int volta;

    scanf ("%[^\n]", palavra);
    getchar ();

    scanf ("%[^\n]", search);
    getchar ();


    volta = busca(search,palavra);

    if (volta >= 0)
        printf ("A palavra começa em: %d\n", volta);
    else if (volta == -1)
        printf ("Palavra não encontrada\n");
    else printf ("Erro\n");

    return 0;
}