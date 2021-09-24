/*
----------------------------------------------------------------ENUNCIADO----------------------------------------------------------------------
|      Ler linhas da entrada padrão e escrevê-las na saída padrão em ordem alfabética crescente, de forma similar ao comando sort do Unix.    |
-----------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6

char * aloca_vetor (int n) {

    char *vetor;

    vetor = malloc (sizeof(char)*MAX);
    if (! vetor) {
        perror ("Operação inválida");
        exit (1);
    }

   return vetor;

}
char **aloca_matriz (int n) {

    char **matriz;

    matriz = malloc (sizeof(char *)*MAX);
    if (! matriz) {
        perror ("Operação inválida");
        exit (1);
    }

    for (int i = 0; i < MAX; i++) {
        matriz[i] = malloc (sizeof(char)*MAX);
        if (! matriz[i]) {
            perror ("Operação inválida");
            exit (1);
        }
    }
   
   return matriz;
}

void ordena_palavras (char** matriz, int tam) {
   
   int i, j, k, min_linha;
   char *ptraux;

   for (i = 0; i < tam; i++) {
      j = 0;
      min_linha = i;

      for (k = i + 1; k < tam; k++ ) {
         if (matriz[k][j] < matriz[min_linha][j] )
              min_linha = k;

         if (matriz[k][j] == matriz[min_linha][j] ) {
            
            while ((matriz[k][j] == matriz[min_linha][j]) && (matriz[k][j] != '\0') && (matriz [min_linha][j] != '\0'))
               j++;

            if (matriz[k][j] < matriz[min_linha][j])
               min_linha = k;
         }
         
         if ( min_linha != i) {

             ptraux = matriz[i];
             matriz[i] = matriz[min_linha];
             matriz[min_linha] = ptraux;
         }
      }

   }
        
}

void escreve_palavras (char **matriz, int tam) {

    int i;

    for (i = 0; i < tam; i++) {
        printf ("%s\n", matriz[i]);
    }
}

void libera_alocacao (char **matriz, char *vetor, int tam ) {

    free (vetor);
    for (int i = 0; i < tam; i++)
        free (matriz[i]);

   free (matriz);
}

int main () {

   int i;
   char *linha, **palavras;
   
   i = 0;
   linha = aloca_vetor (MAX);
   palavras = aloca_matriz (MAX);

   fgets (linha, MAX, stdin);
   while ( (i < MAX) && ((strcmp (linha, "x")) != 0)){
      strcpy (palavras[i], linha);
      fgets (linha, MAX, stdin);
      i++;
   } 

   ordena_palavras (palavras, i);

   escreve_palavras (palavras, i);

   libera_alocacao (palavras, linha, i);

   return 0;
}


