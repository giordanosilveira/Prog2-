#include<stdio.h>
#include<stdlib.h>

#define MAX 100
int main () {

	char str[MAX];
	int i;

	fgets (str, MAX, stdin);
	
	for (i = 0; str[i] != '\0'; i++) {
	}

	printf ("%d", i);
	return 0;
}
