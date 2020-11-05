#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100;
void troca (int *a, int *b){

	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}
int particiona (int *ent, int ini, int fim) {
/*particiona pivo inicio*/
	
	int i,j,pivo;
	i=ini+1;
	j=ini;
	pivo=ent[ini];
	for (i=ini+1;i<=fim;i++) {
		if (ent[i]<pivo) {
			troca (&ent[i],&ent[j]);
			j++;
		}
	}
	troca (&pivo,&ent[j]);
	return j;
}
void quicksort (int *ent, int ini, int fim) {

	int pivo;
	if (ini<fim) {
		pivo=particiona(ent,ini,fim);
		quicksort (ent,ini,pivo);
		quicksort (ent,pivo+1,fim);
	}
}
char ** allctMem () {

	char **matrix;
	int i;

	matrix = (char**)malloc(sizeof(char *)*MAX);
	for (i = 0; i < MAX; i++)
		matrix[i] = (char*)malloc(sizeof(char)*MAX);
		
	return matrix;

}
int main () {
	
	char **words;
	
	words = allctMem ();


	return 0;
}
