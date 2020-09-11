#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

int main () {

	char ori[MAX], cpy[MAX];
	int i, size;

	fgets (ori, MAX, stdin);
	size = strlen (ori);

	if (size == 0) { 
		printf ("There is nothing to copy\n");
		exit (1);
	}
	  	
	for (i = 0; i <= size; i++) 
		cpy[i] = ori[i];
		
	printf ("%s\n", ori);
	printf ("%s\n", cpy);

	return 0;
}
