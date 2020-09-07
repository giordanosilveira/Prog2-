#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int main () {

	char str[MAX+1];
	int i, len;
	len = 0;

	fgets (str, MAX, stdin);	

	for (i = 0; str[i] != '\0'; i++ ) {
		len++;
	}

	printf ("The string lenght is %d\n ", len-1);

	return 0;
}
